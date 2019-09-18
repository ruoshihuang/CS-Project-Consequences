// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "characterassignment.h"

CharacterAssignment::CharacterAssignment(BaseWindow *parent) : BaseWindow(parent)
{
    header = new QLabel("This is your character!");
    header->setStyleSheet("color: grey;"
                               "font-size: 40px;"
                               "font-weight: bold;"
                               "font-family: courier;"
                          "border-radius: 15px;"
                          "padding: 10px;"
                          "background-color: rgba(255, 255, 255, 70%);");

    //will be filled in from a file
    character_pic = new QLabel;
    character_description = new QLabel;
    character_description->setWordWrap(true);
    character_description->setStyleSheet("color: grey;"
                                         "font-size: 30px;"
                                         "font-weight: bold;"
                                         "font-family: courier;"
                                         "border-radius: 15px;"
                                         "padding: 10px;"
                                         "background-color: rgba(255, 255, 255, 70%);");


    next_button = new QPushButton("Next");
    next_button->setStyleSheet("QPushButton"
                               "{background-color: pink;"
                                "border-style: solid;"
                                "border-width: 5px;"
                                "border-color: white;"
                                "font-size: 30px;"
                                "font-weight: bold;"
                                "font-family: courier;"
                                "max-width: 600px;"
                                "min-width: 600px;"
                                "max-height: 50px;"
                                "min-height: 50px;}"
                                "QPushButton:hover"
                                "{background-color: rgb(249, 215, 92)}"
                                "QPushButton:pressed"
                                "{background-color: rgb(197, 249, 107);}");

    layout = new QGridLayout;
    layout->addWidget(header, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(character_pic, 1, 0);
    layout->addWidget(character_description, 1, 1);
    layout->addWidget(next_button, 2, 0, 1, 2, Qt::AlignCenter|Qt::AlignBottom);
    layout->addLayout(toolbar, 3, 0, 1, 2);

    setLayout(layout);
}

