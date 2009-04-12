#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
public:
    Worker();
QString syntaxCheck (const QString &op, const QString &args);
 private:

};

#endif // WORKER_H
