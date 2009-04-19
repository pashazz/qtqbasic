#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTranslator>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator qTr;
    if (!qTr.load(":/translations/tr_" + QLocale::system().name())) {
        qDebug() <<  "cannot load translation: " + QLocale::system().name();


    }
    a.installTranslator(&qTr);
    QTranslator qttr;

    MainWindow w;
    w.show();
    return a.exec();
}
