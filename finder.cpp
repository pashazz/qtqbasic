#include "finder.h"
#include "ui_finder.h"
#include <QtGui>
Finder::Finder(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Finder)
{
    m_ui->setupUi(this);
}

Finder::~Finder()
{
    delete m_ui;
}

void Finder::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
QString Finder::getFindText() {
return m_ui->lineEdit->text();
}
/*
QTextDocument::FindFlags Finder::getFlags() {
   QTextDocument::FindFlags  ret = 0;
    int i = 0;
    if (m_ui->cbBackward->checkState() == Qt::Checked)
    i +=0x00001;
    if (m_ui->cbCaseSensitive->checkState() == Qt::Checked)
  i += 0x00002;
    if (m_ui->cbWholeWords->checkState() == Qt::Checked)
      i += 0x00004;
    ret = i;
          return ret;}
*/
