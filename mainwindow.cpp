#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "runwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    connect (ui->actionRun_Program, SIGNAL (triggered()), this, SLOT (onRun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRun() {
    runWindow *w = new runWindow(this);
    w->start (ui->plainTextEdit->toPlainText());
    w->show();
}





void MainWindow::on_cmdRun_clicked()
{

}
