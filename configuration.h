#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>

namespace Ui {
class Configuration;
}

class Configuration : public QDialog
{
    Q_OBJECT

public:
    explicit Configuration(QWidget *parent = 0);
    ~Configuration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Configuration *ui;

signals:
    void baudRateIsChosen(QString);
    void dataBitsAreChosen(QString);
    void parityIsChosen(QString);
    void stopBitsAreChosen(QString);
};

#endif // CONFIGURATION_H
