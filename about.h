#ifndef ABOUT_H
#define ABOUT_H

#include <QtGui/QDialog>

namespace Ui {
    class about;
}

class about : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(about)
public:
    explicit about(QWidget *parent = 0);
    virtual ~about();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::about *m_ui;

private slots:
    void on_cmdOK_clicked();
};

#endif // ABOUT_H
