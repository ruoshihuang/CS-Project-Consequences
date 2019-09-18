// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef FIREGAME_H
#define FIREGAME_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QGridLayout>
#include <QMovie>

/**
 * The FireGame class
 * @brief the window for the fire game
 */
class FireGame : public QWidget
{
    Q_OBJECT
public:
    explicit FireGame(QWidget *parent = nullptr);

    QLabel *instructions;
    QMovie *fire;
    QLabel *extinguisher;
    QPushButton *button;
    QGridLayout *layout;

public slots:
    /**
     * set_win_text
     * @brief sets the text for when the user wins the game
     */
    void set_win_text();
};

#endif // FIREGAME_H
