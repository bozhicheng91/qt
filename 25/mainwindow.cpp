#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}
//构造函数
PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    //设置窗口大小和标题
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    //创建QPainter 对象
    QPainter painter(this);

    QPen pen;

    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 3 << space << 9 << space
           << 27 << space << 9 << space;

    pen.setDashPattern(dashes);
    painter.setPen(pen);

    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);


}
