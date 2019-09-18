// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef BINARYCHOICEWINDOW_H
#define BINARYCHOICEWINDOW_H

#include "basewindow.h"
#include <QLabel>

/**
 * The BinaryChoiceWindow class
 * @brief the window for the binary choices
 * derived from base window
 */
class BinaryChoiceWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit BinaryChoiceWindow(BaseWindow *parent = nullptr);

    QLabel *text;
    QPushButton *choice1;
    QPushButton *choice2;
    QGridLayout *layout;

private:
    int page_num;
};

#endif // BINARYCHOICEWINDOW_H
