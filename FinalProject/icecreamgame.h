// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef ICECREAMGAME_H
#define ICECREAMGAME_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QKeyEvent>
#include"oneparticle.h"
#include "icecreamcup.h"

/**
 * The IceCreamGame class
 * @brief the window for the ice cream game
 */
class IceCreamGame : public QWidget
{
    Q_OBJECT
public:
    explicit IceCreamGame(QWidget *parent = nullptr);

    QLabel *instructions;
    QGridLayout *grid; //grid to hold all particles
    QVBoxLayout *layout; //window layout
    IceCreamCup *cup;
    std::vector<OneParticle*> particle;
    std::vector<int> passed_row_index;
    std::vector<int> passed_col_index;

    /**
     * keyPressEvent
     * @brief facilitates moving the ice cream cup
     * @param event
     */
    void keyPressEvent(QKeyEvent *event) override;

    /**
     * closeEvent
     * @brief overloaded function to emit a signal when window closes
     * @param event
     */
    void closeEvent(QCloseEvent *event) override;

signals:
    /**
     * gameClosed
     * @brief signals the game has closed
     */
    void gameClosed();

public slots:
    /**
     * generateParticles
     * @brief generate the ice cream balls on the window
     */
    void generateParticles();

private:
    int count; //count how many particles were collected
    int num_particles; //the number of particles on the grid
    int cup_col; //cup's column index
    int cup_row; //cup's row index
};

#endif // ICECREAMGAME_H
