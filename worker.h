#ifndef WORKER_H
#define WORKER_H
#include <QtGui>

enum Operation {op, variable};
  typedef QPair <QString, QString> var;
  typedef QList <var> VarList;
enum VarType {symbol,number, incorrect};

    typedef QList <var> VarList;
class Worker : public QObject

{
public:
    typedef QPair <QString, QString> var;
    typedef QList <var> VarList;
    Worker();
    VarList  getVariables () {return _vars;}
    void addVariable (const var&);
    VarType getType (var &vari);
    void replaceVarsValues (QString &code);
    Operation detectOper (const QString &codeString);
 private:
 VarList _vars;
};

#endif // WORKER_H
