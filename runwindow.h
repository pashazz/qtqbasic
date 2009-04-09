#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QtGui>

namespace Ui {
    class runWindow;
}

class runWindow : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(runWindow)
public:
    explicit runWindow(QWidget *parent = 0);
    virtual ~runWindow();
    int start (QString code);

protected:
    virtual void changeEvent(QEvent *e);
   void onLine (QString args);
    void onCircle (QString args);
    void onPaint (QString args);
private:
    Ui::runWindow *m_ui;
    QGraphicsScene *scene;
int runCode (QString op, QString args);
    //onDraw

};

#endif // RUNWINDOW_H