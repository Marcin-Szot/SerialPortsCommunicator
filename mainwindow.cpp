#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->textBrowser->setFontFamily("Consolas");

    kernel = KernelModule::getKernel();

    ports = new AvailablePorts();
    ports->setModal(true);
    connect(ports, SIGNAL(portIsChosen(QString)), this, SLOT(setPort(QString)));

    config = new Configuration();
    config->setModal(true);
    connect(config, SIGNAL(baudRateIsChosen(QString)), this, SLOT(setBaudRate(QString)));
    connect(config, SIGNAL(dataBitsAreChosen(QString)), this, SLOT(setDataBits(QString)));
    connect(config, SIGNAL(parityIsChosen(QString)), this, SLOT(setParity(QString)));
    connect(config, SIGNAL(stopBitsAreChosen(QString)), this, SLOT(setStopBits(QString)));

}

MainWindow::~MainWindow() {
    delete kernel;
    delete ui;
}

void MainWindow::on_actionAvailable_Ports_triggered() {
    ports->refresh(kernel->currentlyAvailablePorts());
    ports->show();
}

void MainWindow::on_actionConfigure_Connection_triggered() {
    config->show();
}

void MainWindow::setBaudRate(QString baud_rate) {
    kernel->setBaudRate(baud_rate);
}

void MainWindow::setDataBits(QString data_bits) {
    kernel->setDataBits(data_bits);
}

void MainWindow::setParity(QString parity) {
    kernel->setParity(parity);
}

void MainWindow::setStopBits(QString stop_bits) {
    kernel->setStopBits(stop_bits);
}

void MainWindow::setPort(QString portName) {
    kernel->setPort(portName);
    //it is possible that we should disconnect port from messageReceived() first
    connect(kernel->getPort(),SIGNAL(readyRead()),this,SLOT(messageReceived()));
}

void MainWindow::messageReceived() {
    QByteArray data = kernel->getPort()->readAll();
    for(int i = 0; i < data.length(); i++) {
        if((int)data.at(i) >=0 && (int)data.at(i) <= 32) {
            //space
            ui->textBrowser->append("[" + QString::number((int)data.at(i)) + "]");
        }
        else {
            ui->textBrowser->append(data);
        }
    }
}
