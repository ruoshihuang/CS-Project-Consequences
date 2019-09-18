// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef GENDERASSIGNMENT_H
#define GENDERASSIGNMENT_H

#include "basewindow.h"
#include <QGridLayout>
#include <QLabel>

/**
 * The GenderAssignment class
 * @brief the window for choosing the gender
 * derived from base window
 */
class GenderAssignment : public BaseWindow
{
    Q_OBJECT
public:
    explicit GenderAssignment(BaseWindow *parent = nullptr);

    QLabel *instruction;
    QPushButton *male;
    QPushButton *female;
    QLabel *male_avatar;
    QLabel *female_avatar;
    QGridLayout *layout;

};

#endif // GENDERASSIGNMENT_H
