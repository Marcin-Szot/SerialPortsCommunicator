#include "mainwindow.h"
#include <QApplication>
#include "kernelmodule.h"

bool KernelModule::isKernelExists = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
