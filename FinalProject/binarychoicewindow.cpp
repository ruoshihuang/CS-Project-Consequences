// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "binarychoicewindow.h"

BinaryChoiceWindow::BinaryChoiceWindow(BaseWindow *parent) : BaseWindow(parent)
{
    text = new QLabel;
    text->setWordWrap(true);
    text->setStyleSheet("color: grey;"
                        "font-size: 40px;"
                        "font-weight: bold;"
                        "font-family: courier;"
                        "max-width: 1000px;"
                        "min-width: 700px;"
                        "border-radius: 15px;"
                        "padding: 10px;"
                        "background-color: rgba(255, 255, 255, 70%);");

    choice1 = new QPushButton;
    choice2 = new QPushButton;
    layout = new QGridLayout;

    layout->addWidget(text, 0, 0, Qt::AlignCenter);
    layout->addWidget(choice1, 1, 0, Qt::AlignCenter);
    layout->addWidget(choice2, 2, 0, Qt::AlignCenter);
    layout->addLayout(toolbar, 3, 0);

    setLayout(layout);

    QString name("bi_button");
    choice1->setObjectName(name);
    choice2->setObjectName(name);
    setStyleSheet("QPushButton#bi_button"
                  "{background-color: pink;"
                  "border-style: solid;"
                  "border-width: 5px;"
                  "border-color: white;"
                  "font-size: 30px;"
                  "font-weight: bold;"
                  "font-family: courier;"
                  "max-width: 600px;"
                  "min-width: 600px;"
                  "max-height: 100px;"
                  "min-height: 100px;}"
                  "QPushButton#bi_button:hover"
                  "{background-color: rgb(249, 215, 92)}"
                  "QPushButton#bi_button:pressed"
                  "{background-color: rgb(197, 249, 107);}");
}

