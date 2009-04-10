#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
public:
    Worker(QString op, QString args);
//QRectF int2float (QRect *rect);
 private:

};

#endif // WORKER_H
