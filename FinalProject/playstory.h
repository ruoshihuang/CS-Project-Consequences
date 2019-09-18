// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef PLAYSTORY_H
#define PLAYSTORY_H

#include <QObject>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <QDir>
#include "StoryChoice.h"
#include "AssignmentChoice.h"

/**
 * The PlayStory class
 * @brief the backend engine that makes the calculations
 * it is a QObject to enable the SLOT functionality
 */
class PlayStory : public QObject
{
    Q_OBJECT

public:
    const std::string DIRECTORY = QDir::currentPath().toStdString();

    explicit PlayStory(QObject *parent = nullptr);

    /**
     * get_personality
     * @brief get the personality of the character
     * @return the personality
     */
    char get_personality();

    /**
     * get_gender
     * @brief get the gender of the character
     * @return the gender
     */
    char get_gender();

    /**
     * read_in_trinary_choices
     * @brief read in the trinary choices from file trinaryChoice.txt
     */
    void read_in_trinary_choices();

    /**
     * read_all
     * @brief read in all entries of the files for the game rounds
     * @param file_name name of file to be read
     */
    void read_all(const std::string & file_name);

    /**
     * prime_round1_file
     * @brief set the file to be read for round 1 based on user choice
     */
    void prime_round1_file();

    /**
     * prime_round2_file
     * @brief set the file to be read for round 2 based on user choice
     * @param movie_choice the choice of the movie
     */
    void prime_round2_file(char movie_choice);

    size_t TC_page_idx = 0;
    std::vector<AssignmentChoice*> TC_choices;
    std::vector<AssignmentChoice*> TC_choice1;
    std::vector<AssignmentChoice*> TC_choice2;
    std::vector<AssignmentChoice*> TC_choice3;
    std::map<char, int> counter; //counter for character A, B, C

    //store the name of files to be used for each round
    std::string round1_file;
    std::string round2_file;

    std::vector<std::string> story_question;
    std::vector<StoryChoice> story_choice1;
    std::vector<StoryChoice> story_choice2;

signals:
    /**
     * begin_round_1
     * @brief signal to begin round 1
     */
    void begin_round_1();

    /**
     * begin_round_2
     * @brief signal to begin round 2
     */
    void begin_round_2();

    /**
     * call_tabulate
     * @brief signal to tabulate the points for the round
     * @param index the starting index (of story choice vector) of tabulate
     */
    void call_tabulate(size_t index);

    /**
     * call_end_story
     * @brief signal emitted if story ends prematurely,
     * calls the end_story SLOT in consequences.cpp
     * this will invoke a broken heart ending
     */
    void call_end_story();

    /**
     * call_fill_character
     * @brief signal to fill the character page
     */
    void call_fill_character();

    /**
     * open_fire_game
     * @brief signal to open the fire game
     */
    void open_fire_game();

    /**
     * call_fire_end
     * @brief signal emitted if player ignores fire alarm
     * this will invoke a death by fire ending
     */
    void call_fire_end(); //fire ending is called

public slots:
    /**
     * set_male
     * @brief sets the gender to male
     */
    void set_male();

    /**
     * set_female
     * @brief sets the gender to female
     */
    void set_female();

    /**
     * set_personality
     * @brief sets the personality to p
     * @param p the personality
     */
    void set_personality(char p);

    /**
     * set_choice1
     * @brief sets story_choice1 to chosen for current index
     */
    void set_choice1();

    /**
     * set_choice2
     * @brief sets story_choice2 to chosen for current index
     */
    void set_choice2();

    /**
     * increment_TC_page_idx
     * @brief increment the variable TC_page_idx
     */
    void increment_TC_page_idx();

    /**
     * personality_result
     * @brief this function calls find_max_char() to get the personality result
     */
    void personality_result();

    /**
     * tabulate_points
     * @brief tabulate the points for all chosen story_choice
     * starting from the given index
     * @param index the starting index
     */
    void tabulate_points(size_t index);

private:
    char personality = 'P';
    char gender = 'G';
    bool end_of_story = false;
    int this_round_points = 0;

    //this increments along with choosing to faciliate connections
    size_t BC_index = 0;

    /**
     * read
     * @brief read in one set of questions from the file
     * @param input_file the file that stores the question sets
     * @return true if read in successful, false if reached end of file
     */
    bool read(std::ifstream & input_file);

    /**
     * find_max_char
     * @brief find the max counter
     */
    void find_max_char();
};

#endif // PLAYSTORY_H
