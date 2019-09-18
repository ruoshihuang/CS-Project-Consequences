// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef SOUNDWINDOW_H
#define SOUNDWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QTimer>
#include <QMediaPlayer>
/**
 * The SoundWindow class
 * @brief this is a window widget for sound control
 */
class SoundWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SoundWindow(QWidget *parent = nullptr);
    QHBoxLayout *layout;
    QPushButton *sound_on;
    QPushButton *sound_off;
    QStackedWidget *two_state_sound_button;
    bool allow_state_change = true;
};

#endif // SOUNDWINDOW_H
