// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.


#include "fireendwindow.h"

fireendwindow::fireendwindow(QWidget *parent) : QWidget(parent)
{

    fire_gif = new QLabel;
    quit = new QPushButton("Quit");
    quit->setStyleSheet("QPushButton"
                        "{background-color: grey;"
                         "border-style: solid;"
                         "border-width: 5px;"
                         "border-color: white;"
                         "font-size: 30px;"
                         "font-weight: bold;"
                         "font-family: courier;"
                         "max-width: 650px;"
                         "min-width: 650px;"
                         "max-height: 50px;"
                         "min-height: 50px;}"
                         "QPushButton:hover"
                         "{background-color: red}"
                         "QPushButton:pressed"
                         "{background-color: yellow;}");

    layout = new QGridLayout;
    layout->addWidget(fire_gif, 0, 0, Qt::AlignCenter);
    layout->addWidget(quit, 1, 0);

    setFixedSize(800,650);
    setLayout(layout);
    //fire gif
    //https://goo.gl/images/o4h4PZ
    QMovie *fire = new QMovie(":/Gifs/deathbyfire.gif");
    fire_gif->setMovie(fire);
    fire->start();

    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
}
