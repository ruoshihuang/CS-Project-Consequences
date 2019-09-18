// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "genderassignment.h"

GenderAssignment::GenderAssignment(BaseWindow *parent) : BaseWindow (parent)
{

    instruction = new QLabel("Please pick your gender");
    instruction->setStyleSheet("color: grey;"
                               "font-size: 50px;"
                               "font-weight: bold;"
                               "font-family: courier;"
                               "border-radius: 15px;"
                               "padding: 10px;"
                               "background-color: rgba(255, 255, 255, 70%);");

    male_avatar = new QLabel;
    female_avatar = new QLabel;
    //source:https://goo.gl/images/8zzerS
    QPixmap male_pic(":/Avatars/malepic.png");
    QPixmap female_pic(":/Avatars/femalepic.png");
    male_avatar->setPixmap(male_pic);
    female_avatar->setPixmap(female_pic);

    male = new QPushButton("Male");
    female = new QPushButton("Female");
    QString button_style("QPushButton"
                         "{background-color: pink;"
                         "border-style: solid;"
                         "border-width: 5px;"
                         "border-color: white;"
                         "font-size: 30px;"
                         "font-weight: bold;"
                         "font-family: courier;"
                         "max-width: 300px;"
                         "min-width: 300px;"
                         "max-height: 50px;"
                         "min-height: 50px;}"
                         "QPushButton:hover"
                         "{background-color: rgb(249, 215, 92)}"
                         "QPushButton:pressed"
                         "{background-color: rgb(197, 249, 107);}");
    male->setStyleSheet(button_style);
    female->setStyleSheet(button_style);

    layout = new QGridLayout;
    layout->addWidget(instruction, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(male_avatar, 1, 0, Qt::AlignHCenter|Qt::AlignBottom);
    layout->addWidget(female_avatar, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);
    layout->addWidget(male, 2, 0, Qt::AlignCenter);
    layout->addWidget(female, 2, 1, Qt::AlignCenter);
    layout->addLayout(toolbar, 3, 0, 1, 2);

    setLayout(layout);
}

