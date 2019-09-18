// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include "basewindow.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "authorwindow.h"

/**
 * The EndWindow class
 * @brief the window that displays the ending for the user
 * derived from the base window
 * texts and images are filled in at runtime
 */
class EndWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit EndWindow(BaseWindow *parent = nullptr);
    ~EndWindow();

    QLabel *end_gif;
    QLabel *end_text;
    QGridLayout *layout;
    QPushButton *credits;
    AuthorWindow *author_window;
};

#endif // ENDWINDOW_H
