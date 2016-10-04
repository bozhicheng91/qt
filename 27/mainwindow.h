#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

/*定义PaintedWidget类*/
class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};

/*定义ColorWheel类*/
class ColorWheel : public QWidget
{
    Q_OBJECT
public:
    ColorWheel(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
};


#endif // MAINWINDOW_H
