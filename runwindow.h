#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QtGui>
#include <QRegExp>

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
   void onLine (const QString &args);
    void onCircle (const QString &args);
    void onPaint (const QString &args);
    QColor num2col (short color);
    void onCls (const QString &args);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::runWindow *m_ui;
    void appendOperations();
    QGraphicsItem *it; //использую в Paint
    QGraphicsScene *scene;
    short colornum;
    int runCode (QString op, QString args);
    QStringList drawOperations; //список операторов рисования
    int SCREEN; //номер экрана

};

#endif // RUNWINDOW_H
