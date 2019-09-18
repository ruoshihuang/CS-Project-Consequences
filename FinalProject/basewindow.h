// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "helpwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

/**
 * The BaseWindow class
 * @brief the base window that most windows are derived from
 */
class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);
    virtual ~BaseWindow();
    QPushButton *sound;
    QPushButton *help;
    QPushButton *quit;
    QHBoxLayout *toolbar;
    HelpWindow *help_window;

public slots:
    /**
     * help_function
     * @brief opens a window to show the instructions of the game
     */
    void help_function() const;

};
#endif // BASEWINDOW_H
