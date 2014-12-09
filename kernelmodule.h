#ifndef KERNELMODULE_H
#define KERNELMODULE_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QDebug>

class KernelModule
{
public:
    static KernelModule* getKernel();
    QStringList* currentlyAvailablePorts();
    void setBaudRate(QString baud_rate);
    void setDataBits(QString data_bits);
    void setParity(QString parity);
    void setStopBits(QString stop_bits);
    void setPort(QString portName);
    ~KernelModule();

private:
    KernelModule();
    QSerialPort::DataBits parseDataBits(QString arg);
    QSerialPort::BaudRate parseBoudRate(QString arg);
    QSerialPort::Parity parseParity(QString arg);
    QSerialPort::StopBits parseStopBits(QString arg);
    static bool isKernelExists;
    QSerialPort *port;
};

#endif // KERNELMODULE_H
