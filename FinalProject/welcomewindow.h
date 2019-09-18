// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include "basewindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QMovie>

/**
 * The WelcomeWindow class
 * @brief the welcome window
 */
class WelcomeWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit WelcomeWindow(BaseWindow *parent = nullptr);

    QLabel *title; //title of game
    QPushButton *start; //start button
    QGridLayout *layout; //general layout of window

};

#endif // WELCOMEWINDOW_H
