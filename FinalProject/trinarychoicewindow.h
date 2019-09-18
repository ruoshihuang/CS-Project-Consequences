// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef TRINARYCHOICEWINDOW_H
#define TRINARYCHOICEWINDOW_H

#include "basewindow.h"
#include <QLabel>

/**
 * The TrinaryChoiceWindow class
 * @brief the window for the trinary choices ('pick a word' window)
 */
class TrinaryChoiceWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit TrinaryChoiceWindow(BaseWindow *parent = nullptr);

    QLabel *text;
    QPushButton *choice1;
    QPushButton *choice2;
    QPushButton *choice3;
    QGridLayout *layout;

private:
    int page_num;
};

#endif // TRINARYCHOICEWINDOW_H
