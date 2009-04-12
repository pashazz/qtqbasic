#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QRegExp>
#include <QtGui>
#include "worker.h"
#include "about.h"
namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void onRun();
    void exit ();
    void aboutme ();
    void openFile ();
    bool saveFile ();
    void newFile();
    bool saveAs ();
    void wasModified();
private:
    bool maybeSave();
    bool save (const QString &fileName);
    void load (const QString &fileName);
    void setCurrent (const QString &fileName);
    void ParseText ();
    QString curFile;
    QString strippedName (const QString &fileName);
protected:
    void closeEvent (QCloseEvent *event);
     Ui::MainWindowClass *ui;
};

#endif // MAINWINDOW_H
