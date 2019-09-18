// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "welcomewindow.h"

WelcomeWindow::WelcomeWindow(BaseWindow *parent) : BaseWindow(parent)
{
    title = new QLabel;
    title->setStyleSheet("border-radius: 15px;"
                         "padding: 10px;"
                         "background-color: rgba(255, 255, 255, 70%);");

    //Source: https://loading.io/animation/text/
    QMovie *title_gif = new QMovie(":/Gifs/gametitle.gif");
    title->setMovie(title_gif);
    title_gif->start();

    //customize the start button
    start = new QPushButton("Start");
    start->setStyleSheet("QPushButton"
                         "{background-color: pink;"
                         "border-style: solid;"
                         "border-width: 5px;"
                         "border-color: white;"
                         "font-size: 40px;"
                         "font-weight: bold;"
                         "font-family: courier;"
                         "max-width: 600px;"
                         "min-width: 600px;"
                         "max-height: 100px;"
                         "min-height: 100px;}"
                         "QPushButton:hover"
                         "{background-color: rgb(249, 215, 92)}"
                         "QPushButton:pressed"
                         "{background-color: rgb(197, 249, 107);}");

    layout = new QGridLayout;
    layout->addWidget(title, 0, 0, Qt::AlignCenter);
    layout->addWidget(start, 1, 0);
    layout->addLayout(toolbar, 2, 0, Qt::AlignBottom);

    setLayout(layout);
}

