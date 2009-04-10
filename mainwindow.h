#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QRegExp>
#include <QtGui>
#include "worker.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_cmdRun_clicked();
    void onRun();
    void exit ();
private:
    void ParseText ();
    Ui::MainWindowClass *ui;
};

#endif // MAINWINDOW_H
