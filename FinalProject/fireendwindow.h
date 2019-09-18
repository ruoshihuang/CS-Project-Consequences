// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef FIREENDWINDOW_H
#define FIREENDWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMovie>

/**
 * The fireendwindow class
 * @brief the window for the ending where character dies in fire
 */
class fireendwindow : public QWidget
{
    Q_OBJECT
public:
    explicit fireendwindow(QWidget *parent = nullptr);

    QLabel *fire_gif;
    QPushButton *quit;
    QGridLayout *layout;
};

#endif // FIREENDWINDOW_H
