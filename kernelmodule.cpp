#include "kernelmodule.h"

KernelModule::KernelModule() {
    port = NULL;
}

KernelModule* KernelModule::getKernel()
{
    if(!isKernelExists) {
        isKernelExists = true;
        return new KernelModule();
    } else {
        return NULL;
    }
}

QStringList* KernelModule::currentlyAvailablePorts() {
    QSerialPortInfo *portInfo = new QSerialPortInfo();
    QStringList *list = new QStringList();
    for(int i = 0; i < portInfo->availablePorts().length(); i++) {
        list->append(portInfo->availablePorts().at(i).portName());
    }

    delete portInfo;
    return list;
}

void KernelModule::setBaudRate(QString baud_rate) {
    if(port != NULL) {
        port->setBaudRate(parseBoudRate(baud_rate));
    } else {
        //ERROR EXPLANATION
    }
}

void KernelModule::setDataBits(QString data_bits) {
    if(port != NULL) {
        port->setDataBits(parseDataBits(data_bits));
    } else {
        //ERROR EXPLANATION
    }
}

void KernelModule::setParity(QString parity) {
    if(port != NULL) {
        port->setParity(parseParity(parity));
    } else {
        //ERROR EXPLANATION
    }
}

void KernelModule::setStopBits(QString stop_bits) {
    if(port != NULL) {
        port->setStopBits(parseStopBits(stop_bits));
    } else {
        //ERROR EXPLANATION
    }
}

void KernelModule::setPort(QString portName) {
    QSerialPortInfo *portInfo = new QSerialPortInfo();
    QList<QSerialPortInfo> listOfPorts = portInfo->availablePorts();
    for(int i = 0; i < listOfPorts.length(); i++) {
        if(listOfPorts.at(i).portName() == portName) {
            port = new QSerialPort(listOfPorts.at(i));
            break;
        }

        if(i == listOfPorts.length()) {
            //ERROR EXPLANATION
        }
    }
}

QSerialPort::BaudRate KernelModule::parseBoudRate(QString arg) {
    if(arg == "Baud1200") {
        return QSerialPort::Baud1200;
    } else if(arg == "Baud2400") {
        return QSerialPort::Baud2400;
    } else if(arg == "Baud4800") {
        return QSerialPort::Baud4800;
    } else if(arg == "Baud9600") {
        return QSerialPort::Baud9600;
    } else if(arg == "Baud19200") {
        return QSerialPort::Baud19200;
    } else if(arg == "Baud38400") {
        return QSerialPort::Baud38400;
    } else if(arg == "Baud57600") {
        return QSerialPort::Baud57600;
    } else if(arg == "Baud115200") {
        return QSerialPort::Baud115200;
    } else {
        return QSerialPort::UnknownBaud;
    }
}

QSerialPort::DataBits KernelModule::parseDataBits(QString arg) {
    if(arg == "Data5") {
        return QSerialPort::Data5;
    } else if(arg == "Data6") {
        return QSerialPort::Data6;
    } else if(arg == "Data7") {
        return QSerialPort::Data7;
    } else if(arg == "Data8") {
        return QSerialPort::Data8;
    } else {
        return QSerialPort::UnknownDataBits;
    }
}

QSerialPort::Parity KernelModule::parseParity(QString arg) {
    if(arg == "NoParity") {
        return QSerialPort::NoParity;
    } else if(arg == "EvenParity") {
        return QSerialPort::EvenParity;
    } else if(arg == "OddParity") {
        return QSerialPort::OddParity;
    } else if(arg == "SpaceParity") {
        return QSerialPort::SpaceParity;
    } else if(arg == "MarkParity") {
        return QSerialPort::MarkParity;
    }else {
        return QSerialPort::UnknownParity;
    }
}

QSerialPort::StopBits KernelModule::parseStopBits(QString arg) {
    if(arg == "OneStop") {
        return QSerialPort::OneStop;
    } else if(arg == "OneAndHalfStop") {
        return QSerialPort::OneAndHalfStop;
    } else if(arg == "TwoStop") {
        return QSerialPort::TwoStop;
    } else {
        return QSerialPort::UnknownStopBits;
    }
}
