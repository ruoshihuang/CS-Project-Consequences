// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "icecreamgame.h"

IceCreamGame::IceCreamGame(QWidget *parent) : QWidget(parent)
{
    count = 0;
    num_particles = 6; //set the default number of particles to be 6
    cup_col = 0;
    cup_row = 0;
    instructions = new QLabel("Press the arrow keys to move the ice cream cup to collect all the ice cream balls.");
    instructions->setWordWrap(true);
    instructions->setStyleSheet("color: grey;"
                                "font-size: 40px;"
                                "font-weight: bold;"
                                "font-family: courier;"
                                "max-width: 700px;"
                                "min-width: 600px;"
                                "border-radius: 15px;"
                                "padding: 10px;"
                                "background-color: rgba(255, 255, 255, 70%);");

    grid = new QGridLayout;
    layout = new QVBoxLayout;
    layout->addWidget(instructions, Qt::AlignCenter);
    layout->addLayout(grid);
    setLayout(layout);

    cup = new IceCreamCup;
    setFocusPolicy(Qt::StrongFocus);
    grid->addWidget(cup, 0, 0, Qt::AlignCenter);

    //mark the axis of the grid
    //mark x-axis
    for(int i = 0; i < 10; ++i) {
        QString str = QString::number(i);
        QLabel *number = new QLabel(str);
        grid->addWidget(number, 10, i, Qt::AlignCenter);
        grid->setColumnMinimumWidth(i, 55);

    }
    //mark y-axis
    for(int i = 0; i < 10; ++i) {
        QString str = QString::number(i);
        QLabel *number = new QLabel(str);
        grid->addWidget(number, i, 10, Qt::AlignCenter);
        grid->setRowMinimumHeight(i, 55);
    }

    generateParticles();

    //set window size
    setFixedSize(800,650);

    //setting the background image
    //https://goo.gl/images/YZ8V8k
    QPixmap background(":/Background/icecreambackground.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void IceCreamGame::generateParticles() {
    //randomly generate particles on the grid
    for(int i = 0; i < num_particles; ++i) {
        OneParticle *part = new OneParticle;
        particle.push_back(part);
        grid->addWidget(part, part->get_row_index(), part->get_col_index(), Qt::AlignCenter);
    }
}

void IceCreamGame::keyPressEvent(QKeyEvent *event){
    //set up the movements done by each key
    switch (event->key()) {
    case Qt::Key_Left:
       if(cup_col > 0) {cup_col -= 1;} break;
    case Qt::Key_Right:
       if(cup_col < 9) {cup_col += 1;} break;
    case Qt::Key_Up:
       if(cup_row > 0) {cup_row -= 1;} break;
    case Qt::Key_Down:
       if(cup_row < 9) {cup_row += 1;} break;
    default:
        QWidget::keyPressEvent(event);
    }
    repaint();
    QCoreApplication::processEvents();
    grid->addWidget(cup, cup_row, cup_col, Qt::AlignCenter);
    //bool all_collected = false;

    //check for each particle if it has been collected
    for(size_t i = 0; i < particle.size(); ++i) {
        //if the cup lands at same place as the particle, hide particle
        //and update the passed index vectors
        if(cup_row == particle[i]->get_row_index() && cup_col == particle[i]->get_col_index()) {
            particle[i]->hide();

            bool passed_before = false;
            //loop through the previously passed coordinates, increment count only if
            //current coordinates have not been previously passed by ice cream cup
            for(size_t j = 0; j < passed_row_index.size(); ++j){
                if(cup_row == passed_row_index[j] && cup_col == passed_col_index[j]){
                    passed_before = true;
                }
            }

            //increment count only when the particle has not been passed before
            if(!passed_before){
                ++count; //increment count of number of particles collected
            }

            passed_row_index.push_back(cup_row);
            passed_col_index.push_back(cup_col);
        }
    }

    //if the count equals number of particles, indicates game won
    if(count == num_particles){
        close();
    }
    return;
}

void IceCreamGame::closeEvent(QCloseEvent *event){
    emit gameClosed();
    event->accept();
}

