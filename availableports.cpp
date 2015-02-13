#include "availableports.h"
#include "ui_availableports.h"

AvailablePorts::AvailablePorts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AvailablePorts)
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),this, SLOT(itemChosen(QListWidgetItem*)));
}

void AvailablePorts::refresh(QStringList *list)
{
    ui->listWidget->clear();
    for(int i = 0; i < list->length(); i++) {
        ui->listWidget->addItem(list->at(i));
    }
    delete list;
}

AvailablePorts::~AvailablePorts()
{
    delete ui;
}

void AvailablePorts::itemChosen(QListWidgetItem* itm) {
    emit portIsChosen(itm->text());
    this->close();
}
