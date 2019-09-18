// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "authorwindow.h"
#include <QString>
AuthorWindow::AuthorWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Credits");
    setFixedSize(500,300);

    layout = new QGridLayout;

    title = new QLabel("Contributors");

    title->setStyleSheet("color: grey;"
                         "font-size: 45px;"
                         "font-weight: bold;"
                         "font-family: courier;"
                         "border-radius: 15px;"
                         "padding: 10px;"
                         "background-color: rgba(255, 255, 255, 70%);");

    //setting the background image
    //source: https://freedesignfile.com/293509-pink-floral-background-hd-picture/
    QPixmap background(":/Background/PinkFloral.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    layout->addWidget(title, 0, 0, Qt::AlignCenter);


    name1 = new QLabel("Naomi(Youjun) Chen");
    name2 = new QLabel("Lucy(Ruoshi) Huang");

    QString label_style("color: grey;"
                        "font-size: 40px;"
                        "font-weight: bold;"
                        "font-family: courier;"
                        "border-radius: 15px;"
                        "padding: 10px;"
                        "background-color: rgba(255, 255, 255, 70%);");
    name1->setStyleSheet(label_style);
    name2->setStyleSheet(label_style);

    layout->addWidget(name1,1,0,Qt::AlignCenter);
    layout->addWidget(name2,2,0,Qt::AlignCenter);

    setLayout(layout);
}

AuthorWindow::~AuthorWindow(){}
