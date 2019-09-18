// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "oneparticle.h"
#include "stdlib.h"

OneParticle::OneParticle(QWidget *parent) : QWidget(parent) {
    row_index = rand() % 10;
    col_index = rand() % 10;

    width = 35;
    height = 35;
    setMinimumWidth(width + 1);
    setMinimumHeight(height + 1);
}

void OneParticle::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //ice cream scoop
    //source: https://goo.gl/images/AmLG1S
    QPixmap ice_cream_ball(":/Icons/icecreamball.png");
    painter.drawPixmap(0, 0, width, height, ice_cream_ball);
}
