// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "basewindow.h"
#include <QMediaPlayer>

BaseWindow::BaseWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Consequences");

    //icons for the pushbuttons in the toolbar
    //source:https://www.iconfinder.com/
    QPixmap soundIcon(":/Icons/soundicon.png");
    QPixmap helpIcon(":/Icons/helpicon.png");
    QPixmap quitIcon(":/Icons/quiticon.png");

    sound = new QPushButton(soundIcon,"Sound");
    help = new QPushButton(helpIcon,"Instructions");
    quit = new QPushButton(quitIcon,"Exit");
    help_window = new HelpWindow;

    toolbar = new QHBoxLayout;
    toolbar->addWidget(sound);
    toolbar->addWidget(help);
    toolbar->addWidget(quit);

    QObject::connect(help, SIGNAL(clicked()), this, SLOT(help_function()));

}

BaseWindow::~BaseWindow(){
    delete help_window;
}

void BaseWindow::help_function() const{ 
    help_window->show();
}


