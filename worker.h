#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
public:
    Worker(QString op, QString args);

 private:

};

#endif // WORKER_H
