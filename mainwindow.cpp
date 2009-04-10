#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "runwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    connect (ui->actionRun,SIGNAL (triggered()), this, SLOT (onRun()));
    connect (ui->actionExit, SIGNAL (triggered()), this, SLOT (exit()));
   //this->setLayout(ui->Hlay);
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



void MainWindow::exit () {
    qApp->exit();
}

void MainWindow::on_cmdRun_clicked()
{
onRun();
}
