// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef CONSEQUENCES_H
#define CONSEQUENCES_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMovie>
#include <vector>
#include "welcomewindow.h"
#include "genderassignment.h"
#include "binarychoicewindow.h"
#include "trinarychoicewindow.h"
#include "characterassignment.h"
#include "endwindow.h"
#include "icecreamgame.h"
#include "firegame.h"
#include "playstory.h"
#include "fireendwindow.h"
#include "soundwindow.h"

/**
 * The Consequences class
 * @brief the front end engine that links the windows and make the connections
 */
class Consequences : public QWidget
{
    Q_OBJECT
public:
    explicit Consequences(QWidget *parent = nullptr);
    ~Consequences();

    QVBoxLayout *layout; //to put the window_stack inside

    QStackedWidget *window_stack;
    WelcomeWindow *welcome_page;
    GenderAssignment *gender_page;
    std::vector<TrinaryChoiceWindow*> TC_page; //vector to hold all trinary choice pages
    CharacterAssignment *character_page;
    std::vector<BinaryChoiceWindow*> BC_page; //vector to hold all binary choice pages
    EndWindow *end_page;
    fireendwindow *fire_end_page;

    IceCreamGame *ice_cream_game;
    FireGame *fire_game;
    PlayStory *playstory;

    QMediaPlayer *music;
    bool allow_state_change = true;
    SoundWindow *sound_window;

    size_t page_num; //page number for the window stack
    size_t current_index;//current size of playstory

signals:
    /**
     * send_page_num
     * @brief send the current page number of the window stack
     * @param page_num current page of the window stack
     */
    void send_page_num (size_t page_num);

    /**
     * call_personality_result
     * @brief a signal to call personality_result() in playstory
     */
    void call_personality_result();

public slots:
    /**
     * next_page
     * @brief emits the signal to trigger showing the next page
     */
    void next_page();

    /**
     * show_page
     * @brief show the page indexed as 'page_num' in the window stack
     * note that indexing of page_num begins at 0 in order to
     * cohere to the indexing of stacked widgets
     * @param page_num the index of the page in the window stack
     */
    void show_page(size_t page_num) const;

    /**
     * connect_round1
     * @brief make the connections to play round 1
     */
    void connect_round1();

    /**
     * connect_round2
     * @brief make the connections to play round 2
     */
    void connect_round2();

    /**
     * end_story
     * @brief end_story sets the index of window stack to end page
     */
    void end_story();

    /**
     * fill_character_page
     * @brief fill the character page based on the user's choice
     */
    void fill_character_page();

    /**
     * fill_good_ending
     * @brief fill the end page with a good ending
     */
    void fill_good_ending();

    /**
     * fill_bad_ending
     * @brief fill the end page with a bad ending
     */
    void fill_bad_ending();

    /**
     * turn_on_sound
     * @brief turn on the sound
     */
    void turn_on_sound();

    /**
     * turn_off_sound
     * @brief turn of the sound
     */
    void turn_off_sound();

    /**
     * setStateChangeToTrue
     * @brief set variable allow_state_change to true
     */
    void setStateChangeToTrue();

    /**
     * set_tri_choice_text
     * @brief file in the text of trinary choices
     */
    void set_tri_choice_text();

    /**
     * set_chosen_TC_choice1
     * @brief mark choice 1 chosen
     */
    void set_chosen_TC_choice1();

    /**
     * set_chosen_TC_choice2
     * @brief mark choice2 chosen
     */
    void set_chosen_TC_choice2();

    /**
     * set_chosen_TC_choice3
     * @brief mark choice3 chosen
     */
    void set_chosen_TC_choice3();

private:
    /**
     * make_connections
     * @brief make preliminary connections (to be placed in constructor)
     */
    void make_connections();

    /**
     * make_BC_connections
     * @brief helper function to make the connections for the BC pages
     * @param i the index of the BC page
     */
    void make_BC_connections(size_t i);

};

#endif // CONSEQUENCES_H
