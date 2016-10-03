#include "mainwindow.h"
#include <QDebug>

// ---------- custombutton.cpp ---------- //
CustomButton::CustomButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, &CustomButton::clicked,
            this, &CustomButton::onButtonCliecked);
}

void CustomButton::onButtonCliecked()
{
    qDebug() << "You clicked this!";
}

//重写custombutton的mousePressEvent函数.该函数会将其父类中的相应函数覆盖掉.
void CustomButton::mousePressEvent(QMouseEvent *event){


    if (event->button() == Qt::LeftButton){

        qDebug() << "left";
    }else{

        QPushButton::mousePressEvent(event);

    }





}
