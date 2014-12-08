#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kernelmodule.h"
#include "availableports.h"
#include "configuration.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAvailable_Ports_triggered();
    void on_actionConfigure_Connection_triggered();
    void setBaudRate(QString baud_rate);
    void setDataBits(QString data_bits);
    void setParity(QString parity);
    void setStopBits(QString stop_bits);
    void setPort(QString portName);

private:
    Ui::MainWindow *ui;
    KernelModule *kernel;
    AvailablePorts *ports;
    Configuration *config;
};

#endif // MAINWINDOW_H
