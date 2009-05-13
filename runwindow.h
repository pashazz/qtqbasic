#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QtGui>
#include <QRegExp>
#include "worker.h"

namespace Ui {
    class runWindow;
}

class runWindow : public QDialog {
    Q_OBJECT

public:
    explicit runWindow(QWidget *parent = 0);
    virtual ~runWindow();
    int start (QString code);

    //draw
      void onLine (const QString &args);
    void onCircle (const QString &args);
    void onPaint (const QString &args);
    QColor num2col (short color);
    void onCls (const QString &args);
protected:
    virtual void changeEvent(QEvent *e);

    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::runWindow *m_ui;

    QGraphicsItem *it; //использую в Paint
    QGraphicsScene *scene;
    short colornum;

    int SCREEN; //номер экрана
    Worker *w;

};

#endif // RUNWINDOW_H
