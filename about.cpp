#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::about)
{
    m_ui->setupUi(this);
}

about::~about()
{
    delete m_ui;
}

void about::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void about::on_cmdOK_clicked()
{
    this->close();
}
