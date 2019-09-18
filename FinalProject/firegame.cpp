// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "firegame.h"

FireGame::FireGame(QWidget *parent) : QWidget(parent)
{
    setFixedSize(900, 650);
    instructions = new QLabel("Press and hold \"Extinguish\" to help put out the fire!");
    instructions->setWordWrap(true);
    instructions->setStyleSheet("color: grey;"
                        "font-size: 30px;"
                        "font-weight: bold;"
                        "font-family: courier;");

    button = new QPushButton("Extinguish");
    button->setStyleSheet("QPushButton{background-color: grey;"
                          "border-style: solid;"
                          "border-width: 5px;"
                          "border-color: white;"
                          "font-size: 30px;"
                          "font-weight: bold;"
                          "font-family: courier;"
                          "max-width: 200px;"
                          "min-width: 200px;"
                          "max-height: 100px;"
                          "min-height: 100px;}"
                          "QPushButton:hover{background-color:red}"
                          "QPushButton:pressed{background-color:yellow}");

    //fire gif
    //source: https://goo.gl/images/YXZerm
    fire = new QMovie(":/Gifs/fire.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(fire);
    fire->start();

    //fire extinguisher
    //source: https://goo.gl/images/bYAveK
    extinguisher = new QLabel;
    QPixmap extinguish_pic(":/Icons/extinguisher.png");
    extinguisher->setPixmap(extinguish_pic);
    extinguisher->hide();

    layout = new QGridLayout;
    layout->addWidget(instructions, 0 , 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(processLabel, 1, 0, 2, 1, Qt::AlignCenter);
    layout->addWidget(extinguisher, 1, 1,  Qt::AlignCenter);
    layout->addWidget(button, 2, 1, Qt::AlignCenter);

    setLayout(layout);

    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(3000);
    QObject::connect(button, SIGNAL(pressed()), extinguisher, SLOT(show()));
    QObject::connect(button, SIGNAL(released()), extinguisher, SLOT(hide()));
    QObject::connect(button, SIGNAL(pressed()), timer, SLOT(start()));
    QObject::connect(button, SIGNAL(released()), timer, SLOT(stop()));
    QObject::connect(timer, SIGNAL(timeout()), processLabel, SLOT(hide()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(set_win_text()));

    QTimer *timer2 = new QTimer(this);
    timer2->setSingleShot(true);
    timer2->setInterval(2000);
    QObject::connect(timer, SIGNAL(timeout()), timer2, SLOT(start()));
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(close()));
}

void FireGame::set_win_text(){
    instructions->setText("Yay! You put out the fire!");
}
