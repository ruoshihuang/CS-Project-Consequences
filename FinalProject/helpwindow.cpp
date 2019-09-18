// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("Instructions");
    title = new QLabel("Welcome to Consequences!");
    instructions = new QLabel("1. Click on the buttons based on the prompt.\n\n"
                              "2. You will be assigned a character based on your choices in the first section.\n\n"
                              "3. Then you will play the scenario game given your character assignment.\n\n"
                              "4. Sometimes you may feel your response choices during the game are restricted. "
                              "This is because they are based on the personality of your character. (Hence the name 'Consequences'!)\n\n"
                              "5. There are mini games throughout the game that will be unlocked if you perform well.\n\n"
                              "6. Click on the exit button to exit the game.\n");
    instructions->setWordWrap(true);

    layout = new QGridLayout;
    layout->addWidget(title, 0, 0, Qt::AlignCenter);
    layout->addWidget(instructions, 1, 0);
    setLayout(layout);

    setFixedSize(700, 500);

    //setting the background image
    //source: https://freedesignfile.com/293509-pink-floral-background-hd-picture/
    QPixmap background(":/Background/PinkFloral.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    QString label_style("QLabel"
                        "{color: grey;"
                        "font-size: 20px;"
                        "font-weight: bold;"
                        "font-family: courier;"
                        "border-radius: 15px;"
                        "padding: 10px;"
                        "background-color: rgba(255, 255, 255, 70%);}");
    title->setStyleSheet(label_style);
    instructions->setStyleSheet(label_style);
}
