#include "codeanalyzer.h"

CodeAnalyzer::CodeAnalyzer(const QString &code, QWidget *parent) : w (new Worker()), wind (new runWindow(parent))
{
    _code = code;
    _parent = parent;
    appendOperations();
    start();
}
int CodeAnalyzer::start ()
{
qDebug("analyze code");
    QStringList strs = _code.split("\n");
    QString str;
wind->show();
    foreach (str, strs) {
        //ищем новые переменные
      if (w->detectOper(str) == variable) {
          QStringList list = str.split('=');
          qDebug () << "variable detected";


      }


     if (w->detectOper(str) == op) {
         QRegExp rx ("(^[A-Z]+)",Qt::CaseSensitive,QRegExp::RegExp);
qDebug("operator detected");
//operator here
QString opstr;
int i;
for (i = rx.indexIn(str); i != rx.matchedLength(); ++i) {
    opstr.append(str.at (i));
}


QString strArgs = str.rightRef(str.count() -1 - i).toString();
//if (str.count()  - i == 0) {strArgs = "";} //maybe it need


if (drawOperations.contains(opstr)) {
runOperator(opstr, strArgs);
}


else {
QMessageBox::critical(_parent, tr("QtQBASIC"), tr ("Incorrect operator: %1").arg(opstr));
}

}

 }
wind->update();
}

int CodeAnalyzer::runOperator(QString op, QString args) {
    // Running the operator
    op.toUpper();

    if (op == "CIRCLE") { wind->onCircle(args);}
    else if (op == "LINE") { wind->onLine(args);}
    else if (op == "PAINT") { wind->onPaint(args);}
    else if (op == "CLS") {wind->onCls(args);}
  //  else if (op == "SCREEN"){SCREEN = args.toInt();}
    else {/* here is ERROR */
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("Incorrect operator: ") + op);
        msg.setWindowTitle(tr("Error,aborting"));
        msg.exec();

    return -1;
            }



}
void CodeAnalyzer::appendOperations() {
    drawOperations.append("CIRCLE");
    drawOperations.append("LINE");
    drawOperations.append("PAINT");
    drawOperations.append("SCREEN");
    drawOperations.append("CLS");
}

