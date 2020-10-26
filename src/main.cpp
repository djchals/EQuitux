#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);

    aa.setWindowIcon(QIcon(":/styles/icon_app.png"));
    MainWindow w;
    w.show();

    return aa.exec();
}
