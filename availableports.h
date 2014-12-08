#ifndef AVAILABLEPORTS_H
#define AVAILABLEPORTS_H

#include <QDialog>
#include <QSerialPortInfo>
#include <QListWidgetItem>

namespace Ui {
class AvailablePorts;
}

class AvailablePorts : public QDialog
{
    Q_OBJECT

public:
    explicit AvailablePorts(QWidget *parent = 0);
    void refresh(QStringList* list);
    ~AvailablePorts();

private:
    Ui::AvailablePorts *ui;

private slots:
    void itemChosen(QListWidgetItem* itm);

signals:
    void portIsChosen(QString portName);
};

#endif // AVAILABLEPORTS_H
