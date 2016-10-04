#include "mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

/*PaintedWidget类*/
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
    //打开反走样设置
    painter.setRenderHint(QPainter::Antialiasing, true);
    //创建QLinearGradient对象实例. 该对象为线性渐变.
    //四个参数分别是渐变的起点和终点
    QLinearGradient linearGradient(60, 50, 200, 200);
    //设置渐变颜色. 在指定位置设置颜色
    linearGradient.setColorAt(0.2, Qt::white);
    linearGradient.setColorAt(0.6, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    //创建Bursh对象时, 将创建的渐变对象传递过去
    painter.setBrush(QBrush(linearGradient));
    //绘制椭圆
    painter.drawEllipse(50, 50, 200, 150);
}

/*ColorWheel类*/
//构造函数
ColorWheel::ColorWheel(QWidget *parent) :
    QWidget(parent)
{
    //设置窗口大小和标题
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}
void ColorWheel::paintEvent(QPaintEvent *)
{
    //新建QPainter类,并开启反走样
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    const int r = 400;
    const int s = 300;

    //创建角度渐变实例.
    //前两个参数为角度渐变的中心点.第三个参数为渐变的起始角度值
    QConicalGradient conicalGradient(0, 0, 0);
    //设置给定位置的颜色
    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    painter.translate(r, s);

    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0, 0), 100, 100);
}
