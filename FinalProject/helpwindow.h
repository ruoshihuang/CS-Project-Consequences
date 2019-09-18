// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

/**
 * The HelpWindow class
 * @brief the window that includes the instructions of the game
 */
class HelpWindow : public QWidget
{
    Q_OBJECT
public:
    explicit HelpWindow(QWidget *parent = nullptr);

    QLabel *title;
    QLabel *instructions;
    QGridLayout * layout;

};

#endif // HELPWINDOW_H
