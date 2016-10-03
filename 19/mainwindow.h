#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>

// ---------- custombutton.h ---------- //
class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = 0);
private:
    void onButtonCliecked();
 protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
