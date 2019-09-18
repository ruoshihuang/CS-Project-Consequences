// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "mainwindow.h"
#include <QApplication>
#include "consequences.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Consequences* w = new Consequences;
    w->show();

    w->setAttribute(Qt::WA_DeleteOnClose, true);
    return a.exec();
}
