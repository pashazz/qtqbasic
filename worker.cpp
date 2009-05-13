#include "worker.h"
#include <QtGui>
#include <QRegExp>
Worker::Worker()

{
;
}
void Worker::addVariable(const var &vari) {


    _vars.append(vari);
}

VarType Worker::getType(var &vari) {
    //incorrect возвращается, когда type mismatch
QRegExp rx ("\"([^\"]+)\"");
QString str = vari.second;
if (rx.exactMatch(str)) {
 if (str.at(str.size() -1) == '$') {
    return symbol;
    }

     return incorrect;

}
else {
    return number;
}

}

void Worker::replaceVarsValues(QString &code) {
   var vari; //переменная для перебора
   foreach (vari, _vars) {
       code.replace(vari.first, vari.second, Qt::CaseInsensitive);

   }

}
Operation Worker::detectOper(const QString &codeString) {
    if (codeString.contains('=')) {
        return variable;
    }
    //здесь не доделано
      //find operator
    QRegExp rx ("(^[A-Z]+)",Qt::CaseSensitive,QRegExp::RegExp);
    if (rx.exactMatch(codeString))
        return op;

}
