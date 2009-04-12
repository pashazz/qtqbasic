#ifndef FINDER_H
#define FINDER_H

#include <QtGui/QDialog>
#include <QTextDocument>

namespace Ui {
    class Finder;
}

class Finder : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Finder)
public:
    explicit Finder(QWidget *parent = 0);
    virtual ~Finder();
    QString getFindText();
    QTextDocument::FindFlags getFlags ();
protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Finder *m_ui;
};

#endif // FINDER_H
