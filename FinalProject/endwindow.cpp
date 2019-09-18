// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "endwindow.h"

EndWindow::EndWindow(BaseWindow *parent) : BaseWindow(parent)
{

    end_gif = new QLabel;
    end_text = new QLabel("This will describe the ending of the story");
    end_text->setWordWrap(true);
    end_text->setStyleSheet("color: grey;"
                            "font-size: 30px;"
                            "font-weight: bold;"
                            "font-family: courier;"
                            "border-radius: 15px;"
                            "padding: 10px;"
                            "background-color: rgba(255, 255, 255, 70%);");
    credits = new QPushButton("Credits");
    credits->setStyleSheet("QPushButton"
                          "{background-color: pink;"
                          "border-style: solid;"
                          "border-width: 5px;"
                          "border-color: white;"
                          "font-size: 30px;"
                          "font-weight: bold;"
                          "font-family: courier;"
                          "max-width: 300px;"
                          "min-width: 300px;"
                          "max-height: 100px;"
                          "min-height: 100px;}"
                          "QPushButton:hover"
                          "{background-color: rgb(249, 215, 92)}"
                          "QPushButton:pressed"
                          "{background-color: rgb(197, 249, 107);}");
    layout = new QGridLayout;
    layout->addWidget(end_gif, 0, 0);
    layout->addWidget(credits, 1, 0);
    layout->addWidget(end_text, 0, 1, 2, 1);

    layout->addLayout(toolbar, 2, 0, 1, 2);
    setLayout(layout);

    author_window = new AuthorWindow;
    QObject::connect(credits,SIGNAL(clicked()), author_window, SLOT(show()));
}
EndWindow::~EndWindow(){
    delete  author_window;
}
