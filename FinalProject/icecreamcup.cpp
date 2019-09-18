// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "icecreamcup.h"

IceCreamCup::IceCreamCup(QWidget *parent) : QWidget(parent)
{
    width = 45;
    height = 45;
    setMinimumWidth(width + 1);
    setMinimumHeight(height + 1);
}

void IceCreamCup::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //ice cream cup
    //source: https://goo.gl/images/bmdHVq
    QPixmap ice_cream_cup(":/Icons/icecreamcup.png");
    painter.drawPixmap(0, 0, width, height, ice_cream_cup);
}


