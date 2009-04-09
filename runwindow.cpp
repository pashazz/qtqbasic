#include "runwindow.h"
#include "ui_runwindow.h"


runWindow::runWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::runWindow)
{
    m_ui->setupUi(this);
scene = new QGraphicsScene (this);

  m_ui->gview->setScene(scene);

}
int runWindow::start (QString code)
{


    //spit
    QStringList strs = code.split("\n");
    QString str;
    qDebug () << "strs  is" << strs;
    foreach (str, strs) {
            //find operator
    QRegExp op ("(^[A-Z]+)",Qt::CaseSensitive,QRegExp::RegExp);
/*    if (!op.exactMatch(str)) {
       QMessageBox msg;
       msg.setText("error exp");
       msg.setWindowTitle("error");
       msg.exec();
    return;
    }
*/
//qDebug() << op.matchedLength();
//operator here
QString opstr;
int i;
for (i = op.indexIn(str); i != op.matchedLength(); ++i) {
    opstr.append(str.at (i));
}
qDebug () << "opstr is" << opstr;

QString strArgs = str.rightRef(str.count() -1 - i).toString();
//if (str.count()  - i == 0) {strArgs = "";} //maybe it need
qDebug () << "strArgs is " << strArgs;
 runCode(opstr, strArgs);

}
}
runWindow::~runWindow()
{
    delete m_ui;

}
int runWindow::runCode(QString op, QString args) {
    // Running the operator
    if (op == "CIRCLE") { onCircle(args);}
    else if (op == "LINE") { onLine(args);}
    else if (op == "PAINT") { onPaint(args);}
    else {/* here is ERROR */
    return -1;
            }



}
//this be coming soon
void runWindow::onCircle(QString args) {
    //объявим нужные переменные
    qreal x = 0, y = 0, r = 0;



QStringList lstArgs = args.split(",");
int args_count = lstArgs.count();
if (args_count < 3) {
        QMessageBox msg;
        msg.setText("Please add  arguments");
        msg.setWindowTitle("Error, aborting...");
        msg.exec();
        return;
    }
QString arg;
QList<qreal> argsN; //числа
foreach (arg, lstArgs) {
    arg.remove('(').remove(')'); //удаляем скобки
    argsN.append(arg.toDouble());

}
switch (argsN.count()) {
case 3:
x = argsN.at(0);
y = argsN.at(1);
r = argsN.at(2);
//необходимо отлаживать
QColor c = QColor("Black");
scene->addEllipse(x,y,r,r, QPen (QColor("Black")), QBrush (QColor ("Black"), Qt::SolidPattern));
break;

//case 4:
//указан ЦВЕТ
//mark as TODO
;
}


    }


void runWindow::onPaint (QString args) {
    ;
}
void runWindow::onLine (QString args) {
    //нужные переменные
    qreal x1 = 0, y1 = 0,  x2 = 0,  y2 = 0;


QStringList lstArgs = args.split(",");
int args_count = lstArgs.count();
if (args_count < 3) {
        QMessageBox msg;
        msg.setText("Please add  arguments");
        msg.setWindowTitle("Error, aborting...");
        msg.exec();
        return;
    }
QString arg;
QList<qreal> argsN; //числа
foreach (arg, lstArgs) {
    arg.remove('(').remove(')'); //удаляем скобки
    argsN.append(arg.toDouble());

}

switch (argsN.count()) {
    case 4: //обычное кол-во аргументов, рисую ЧЕРНЫМ
        QLineF l = (x1, x2, y1, y2);
    //    scene->addLine(x1, x2, y1, y2,  QPen (QColor ("Black"));

}
}

void runWindow::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
