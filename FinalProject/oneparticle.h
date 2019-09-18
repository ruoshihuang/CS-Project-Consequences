// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef ONEPARTICLE_H
#define ONEPARTICLE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

/**
 * The OneParticle class
 * @brief this class makes one ice cream ball for the ice cream game
 */
class OneParticle : public QWidget
{
    Q_OBJECT
public:
    explicit OneParticle(QWidget *parent = nullptr);

    /**
     * paintEvent
     * @brief paints one particle
     * @param event
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * get_row_index
     * @brief get the row index of the particle
     * @return the row index of the particle
     */
    int get_row_index() {return row_index;}

    /**
     * get_col_index
     * @brief get the column index of the particle
     * @return the column index of the particle
     */
    int get_col_index() {return col_index;}
private:
    int width; //width of one particle
    int height; //height of one particle
    int row_index; //x-coordinates
    int col_index; //y-coordinates
};

#endif // ONEPARTICLE_H
