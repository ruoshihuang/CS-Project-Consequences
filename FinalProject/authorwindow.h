// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef ANSWERSWINDOW_H
#define ANSWERSWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
/**
 * The AuthorWindow class
 * @brief This is a window widget that shows the contributors of the program
 */
class AuthorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorWindow(QWidget *parent = nullptr);
    ~AuthorWindow();
    QGridLayout* layout;

    QLabel* title;
    QLabel* name1;
    QLabel* name2;
};

#endif // ANSWERSWINDOW_H
