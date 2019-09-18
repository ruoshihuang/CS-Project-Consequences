// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef ICECREAMCUP_H
#define ICECREAMCUP_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QCoreApplication>

/**
 * The IceCreamCup class
 * @brief this class makes the ice cream cup object for
 * the ice cream game
 */
class IceCreamCup : public QWidget
{
    Q_OBJECT
public:
    explicit IceCreamCup(QWidget *parent = nullptr);

    /**
     * paintEvent
     * @brief draws the ice cream cup
     * @param e
     */
    void paintEvent(QPaintEvent *e);

private:
    int width; //width of cup
    int height; //height of cup
};

#endif // ICECREAMCUP_H
