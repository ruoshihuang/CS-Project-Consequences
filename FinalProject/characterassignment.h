// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef CHARACTERASSIGNMENT_H
#define CHARACTERASSIGNMENT_H

#include "basewindow.h"
#include <QWidget>
#include <QLabel>

/**
 * The CharacterAssignment class
 * @brief the window that shows the character assignment
 * derived from base window
 * text and images are filled in at runtime
 */
class CharacterAssignment : public BaseWindow
{
    Q_OBJECT
public:
    explicit CharacterAssignment(BaseWindow *parent = nullptr);

    QLabel *header;
    QLabel *character_pic;
    QLabel *character_description;
    QPushButton *next_button;
    QGridLayout *layout;

};

#endif // CHARACTERASSIGNMENT_H
