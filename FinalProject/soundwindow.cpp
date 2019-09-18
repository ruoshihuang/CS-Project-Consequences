// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "soundwindow.h"

SoundWindow::SoundWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Sound Control");
    layout = new QHBoxLayout;
    setLayout(layout);

    //icons for the pushbuttons in the toolbar
    //source:https://www.iconfinder.com/
    QPixmap soundIcon(":/Icons/soundicon.png");
    sound_on = new QPushButton(soundIcon,"Sound on");
    sound_off = new QPushButton(soundIcon,"Sound off");
    two_state_sound_button = new QStackedWidget;

    layout->addWidget(sound_on);
    layout->addWidget(sound_off);
}






