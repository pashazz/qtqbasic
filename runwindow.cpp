#include "runwindow.h"
#include "ui_runwindow.h"

//this be coming soon
void runWindow::onCircle(QString args) {
   ;
}
void runWindow::onPaint (QString args) {
    ;
}
void runWindow::onLine (QString args) {
    ;
}
runWindow::runWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::runWindow)
{
    m_ui->setupUi(this);

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
