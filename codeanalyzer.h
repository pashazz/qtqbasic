#ifndef CODEANALYZER_H
#define CODEANALYZER_H
#include <QtGui>
#include <QtCore>
#include "worker.h"
#include "runwindow.h"
class CodeAnalyzer : public QObject
{
public:
    CodeAnalyzer(const QString &code, QWidget *parent);

private:
       int start () ;
    QString _code;
    Worker * w;
  void appendOperations();
  QStringList drawOperations;
  int runOperator (QString op, QString args);
  runWindow *wind;
  QWidget *_parent;
};

#endif // CODEANALYZER_H
