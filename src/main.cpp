#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);
    MainWindow w;
    w.show();


    return aa.exec();
}
