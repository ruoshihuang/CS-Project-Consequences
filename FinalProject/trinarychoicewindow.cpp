// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "trinarychoicewindow.h"

TrinaryChoiceWindow::TrinaryChoiceWindow(BaseWindow *parent) : BaseWindow(parent)
{
    text = new QLabel("Pick a word");
    text->setStyleSheet("color: grey;"
                        "font-size: 60px;"
                        "font-weight: bold;"
                        "font-family: courier;"
                        "border-radius: 15px;"
                        "padding: 10px;"
                        "background-color: rgba(255, 255, 255, 70%);");

    choice1 = new QPushButton;
    choice2 = new QPushButton;
    choice3 = new QPushButton;

    layout = new QGridLayout;
    layout->addWidget(text, 0, 0, 1, 3, Qt::AlignCenter);
    layout->addWidget(choice1, 1, 0, Qt::AlignHCenter|Qt::AlignTop);
    layout->addWidget(choice2, 1, 1, Qt::AlignHCenter|Qt::AlignTop);
    layout->addWidget(choice3, 1, 2, Qt::AlignHCenter|Qt::AlignTop);
    layout->addLayout(toolbar, 2, 0, 1, 3);
    setLayout(layout);

    QString name("tri_button");
    choice1->setObjectName(name);
    choice2->setObjectName(name);
    choice3->setObjectName(name);
    setStyleSheet("QPushButton#tri_button "
                  "{background-color: pink;"
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
                  "QPushButton#tri_button:hover"
                  "{background-color: rgb(249, 215, 92)}"
                  "QPushButton#tri_button:pressed"
                  "{background-color: rgb(197, 249, 107);}");
}

