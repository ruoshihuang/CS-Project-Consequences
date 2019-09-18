// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef STORYLINE_STORYCHOICE_H
#define STORYLINE_STORYCHOICE_H

#include "Choice.h"

/**
 * The StoryChoice class
 * @brief this class stores the choices for the story questions
 */
class StoryChoice : public Choice {
public:
    StoryChoice(){}
    ~StoryChoice(){}
    StoryChoice(const std::string & c, int p):Choice(c), points(p){}

    /**
     * set_points
     * @brief set the variable points
     * @param p
     */
    void set_points(int p) {points = p;}


    /**
     * get_points
     * @brief get the variable points
     * @return a integer stored in points
     */
    int get_points() const {return points;}


    /**
     * set_end
     * @brief set the variable end_story to true
     */
    void set_end() {end_story = true;}


    /**
     * get_end
     * @brief   return the variable end
     * @return  a boolean variable stored in end_story
     */
    bool get_end() {return end_story;}

private:
    int points; //the number of points associated with this choice
    bool end_story = false; //whether or not this choice ends the story
};

#endif //STORYLINE_STORYCHOICE_H
