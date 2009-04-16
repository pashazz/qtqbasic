#include "runwindow.h"
#include "ui_runwindow.h"

/*void paint(const QPoint point, int color)
{

   QList<QGraphicsItem *> list = scene->items(point);
   for (int i = 0; i < list.size(); ++i)
       qgraphicsitem_cast<MyItem *>(list.at(i))->setColor(color);
}

*/
runWindow::runWindow(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::runWindow)
{
    m_ui->setupUi(this);
scene = new QGraphicsScene (this);
colornum = -1;
  m_ui->gview->setScene(scene);
  m_ui->gview->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

}
int runWindow::start (QString code)
{
    //spit
    QStringList strs = code.split("\n");
    QString str;
    qDebug () << "strs  is" << strs;
    foreach (str, strs) {
            //find operator
    QRegExp op ("(^[A-Z]+)",Qt::CaseSensitive,QRegExp::RegExp);
/*    if (!op.exactMatch(str)) {
       QMessageBox msg;
       msg.setText("error exp");
       msg.setWindowTitle("error");
       msg.exec();
    return;
    }
*/
//qDebug() << op.matchedLength();
//operator here
QString opstr;
int i;
for (i = op.indexIn(str); i != op.matchedLength(); ++i) {
    opstr.append(str.at (i));
}
qDebug () << "opstr is" << opstr;

QString strArgs = str.rightRef(str.count() -1 - i).toString();
//if (str.count()  - i == 0) {strArgs = "";} //maybe it need
qDebug () << "strArgs is " << strArgs;
runCode(opstr, strArgs);

}
}
runWindow::~runWindow()
{
    delete m_ui;

}

int runWindow::runCode(QString op, QString args) {
    // Running the operator
    if (op == "CIRCLE") { onCircle(args);}
    else if (op == "LINE") { onLine(args);}
    else if (op == "PAINT") { onPaint(args);}
    else if (op == "CLS") {onCls();}
    else {/* here is ERROR */
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Incorrect operator: " + op);
        msg.setWindowTitle("Error,aborting");
        msg.exec();

    return -1;
            }



}
//this be coming soon
void runWindow::onCircle(QString args) {
    //объявим нужные переменные
    qreal x = 0, y = 0, r = 0;


    QStringList lstArgs = args.split(",");
int args_count = lstArgs.count();
if (args_count < 3) {
        QMessageBox msg;
        msg.setText("Please add  arguments");
        msg.setWindowTitle("Error, aborting...");
        msg.exec();
        return;
    }
QString arg;
QList<qreal> argsN; //числа
foreach (arg, lstArgs) {
    arg.remove('(').remove(')').remove ('-'); //удаляем скобки
    argsN.append(arg.toDouble());

}
qreal new_x;
qreal new_y;
switch (argsN.count()) {
case 3:
x = argsN.at(0);
y = argsN.at(1);
r = argsN.at(2);
//необходимо отлаживать
 new_x = x-r;
 new_y = y-r;
scene->addEllipse(new_x,new_y,r,r, QPen (QColor("Black")), QBrush (QColor ("White"), Qt::SolidPattern));
break;

case 4:
QColor c (num2col(argsN.at(3)));
//указан ЦВЕТ
x = argsN.at(0);
y = argsN.at(1);
r = argsN.at(2);
 new_x = x-r;
 new_y = y-r;
scene->addEllipse(new_x,new_y,r,r, QPen (c), QBrush (QColor ("White"), Qt::SolidPattern));
break;
}
    }

void runWindow::onPaint (QString args) {
    qreal x = 0, y =0; //x,y
    short c = 0; //color
    QStringList lstArgs = args.split(",");
int args_count = lstArgs.count();
if (args_count < 2) {
        QMessageBox msg;
        msg.setText("Please add  arguments");
        msg.setWindowTitle("Error, aborting...");
        msg.exec();
        return;
    }
QString arg;
QList<qreal> argsN; //числа
foreach (arg, lstArgs) {
    arg.remove('(').remove(')').remove ('-'); //удаляем скобки
    argsN.append(arg.toDouble());

}
switch (argsN.count()) {
case 3:
    //по-обычному
    x = argsN.at(0);
    y = argsN.at(1);
    c = argsN.at (2);
it = m_ui->gview->scene()->itemAt(x,y);

if (it != 0) {
    qDebug() << "element grabbed: " << it;
    //код ниже нуждается в отладке
    colornum =c;
    if (it != 0  && colornum != -1) {
        QAbstractGraphicsShapeItem *item;
        if  (item == dynamic_cast <QAbstractGraphicsShapeItem * > (it)) {
            item->setBrush(QColor(num2col(colornum)));
        }
    }



}
    else {
        qDebug () << "element not grabbed: ";
        //redraws background
     QBrush b (num2col (c));
     m_ui->gview->setBackgroundBrush(b);
     m_ui->gview->update();
    }
/*if (it == 0) {qDebug("null pointer");
//redraws background
     QBrush b (num2col (c));
     m_ui->gview->setBackgroundBrush(b);
     m_ui->gview->update();

 }
 */
 //draw polygon a
/**************************
 ЗДЕСЬ Я ЗАПУТАЛСЯ СОВСЕМ. ПОМОГИТЕ!! :D
 Нужно решить следующую задачу.
 Залить цветом (с) элемент QGraphicsItem *it. Если он ни на что не
 указывает,залить всю сцену выбранным цветом.
 Спасибо
 *******************************/

}
}
void runWindow::onLine (QString args) {
    //нужные переменные
    qreal x1 = 0, y1 = 0,  x2 = 0,  y2 = 0;


QStringList lstArgs = args.split(",");
int args_count = lstArgs.count();
if (args_count < 3) {
        QMessageBox msg;
        msg.setText("Please add  arguments");
        msg.setWindowTitle("Error, aborting...");
        msg.exec();
        return;
    }
QString arg;
QList<qreal> argsN; //числа
foreach (arg, lstArgs) {
    arg.remove('(').remove(')').remove ('-'); //удаляем скобки
    argsN.append(arg.toDouble());

}

switch (argsN.count()) {
    case 4: //обычное кол-во аргументов, рисую ЧЕРНЫМ
        x1 = argsN.at(0);
y1 = argsN.at (1);
x2 = argsN.at(2);
y2 = argsN.at (3);
        scene->addLine(x1, y1, x2, y2,  QPen (QColor ("Black")));
break;
    case 5: case 6:
        //COLOR
if (lstArgs.count() == 5) {
QColor c (num2col(argsN.at(4)));
 x1 = argsN.at(0);
y1 = argsN.at (1);
x2 = argsN.at(2);
y2 = argsN.at (3);
        scene->addLine(x1, y1, x2, y2,  QPen (c));
    } else if (lstArgs.count() == 6) {
        QBrush b;
        QColor c (num2col(argsN.at(4)));
        if (lstArgs.at(5) == "BF") {b.setColor((c));
          //draw polygon
        x1 = argsN.at(0);
         y1 = argsN.at (1);
     x2 = argsN.at(2);
    y2 = argsN.at (3);
        QPointF X1 (x1,y1);
        QPointF Y1 (x2,y2);
        QRectF rect (X1, Y1);
        QPolygonF p (rect);

        scene->addPolygon(p, QPen (c), QBrush(c));
        return;
        }

        else if (lstArgs.at(5) == "B") {b.setColor(QColor("White"));}
        else {return;}



        //draw polygon
        x1 = argsN.at(0);
         y1 = argsN.at (1);
     x2 = argsN.at(2);
    y2 = argsN.at (3);
        QPointF X1 (x1,y1);
        QPointF Y1 (x2,y2);
        QRectF rect (X1, Y1);
        QPolygonF p (rect);

        scene->addPolygon(p, QPen (c), b);


    }
}
}

void runWindow::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }


}
QColor runWindow::num2col(short color)

{
            QColor c;

   if (color == 0) {
       c.setNamedColor("Black");

   }
   if (color == 1) {
    c.setNamedColor("Dark Blue");
   }
   if (color == 2) {
       c.setNamedColor("Dark Green");
   }
   if (color == 3) {
c.setNamedColor("Dark Cyan");
   }
   if (color == 4) {
       c.setNamedColor("Dark Red");
   }
   if (color == 5) {
       c.setNamedColor("Dark Purple");
         }
   if (color == 6) {
       c.setNamedColor("Orange Brown");
          }
   if (color == 7) {
       c.setNamedColor("Grey");
   }
if (color == 8) {
    c.setNamedColor("Dark Grey");
}
if (color == 9) {
    c.setNamedColor("Light Blue");
}
if (color == 10) {
    c.setNamedColor("Light Green");
}
if (color == 11) {c.setNamedColor("Light Cyan");}
if (color == 12) {c.setNamedColor("Light Red");}
if (color == 13) {c.setNamedColor("Magenta");}
if (color == 14) {c.setNamedColor("White");}
            return c;

}


void runWindow::onCls() {
    scene->clear();
}
