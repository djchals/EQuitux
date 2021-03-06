#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication aa(argc, argv);
    aa.setWindowIcon(QIcon(":/styles/equitux.png"));
    QFile stylesheet_file(":/styles/equimain.qss");
    stylesheet_file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesheet_file.readAll());
    aa.setStyleSheet(stylesheet);

    MainWindow w;
    w.show();

    return aa.exec();
}
