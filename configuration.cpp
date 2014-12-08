#include "configuration.h"
#include "ui_configuration.h"

Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Baud1200");
    ui->comboBox->addItem("Baud2400");
    ui->comboBox->addItem("Baud4800");
    ui->comboBox->addItem("Baud9600");
    ui->comboBox->addItem("Baud19200");
    ui->comboBox->addItem("Baud38400");
    ui->comboBox->addItem("Baud57600");
    ui->comboBox->addItem("Baud115200");
    ui->comboBox->addItem("UnknownBaud");

    ui->comboBox_2->addItem("Data5");
    ui->comboBox_2->addItem("Data6");
    ui->comboBox_2->addItem("Data7");
    ui->comboBox_2->addItem("Data8");
    ui->comboBox_2->addItem("UnknownDataBits");

    ui->comboBox_3->addItem("NoParity");
    ui->comboBox_3->addItem("EvenParity");
    ui->comboBox_3->addItem("OddParity");
    ui->comboBox_3->addItem("SpaceParity");
    ui->comboBox_3->addItem("MarkParity");
    ui->comboBox_3->addItem("UnknownParity");

    ui->comboBox_4->addItem("OneStop");
    ui->comboBox_4->addItem("OneAndHalfStop");
    ui->comboBox_4->addItem("TwoStop");
    ui->comboBox_4->addItem("UnknownStopBits");
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::on_pushButton_clicked()
{
    emit baudRateIsChosen(ui->comboBox->currentText());
    emit dataBitsAreChosen(ui->comboBox_2->currentText());
    emit parityIsChosen(ui->comboBox_3->currentText());
    emit stopBitsAreChosen(ui->comboBox_4->currentText());
    this->close();
}
