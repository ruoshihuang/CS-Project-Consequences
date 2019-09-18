// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#pragma once
#ifndef BACKEND_ASSIGNMENTCHOICE_H
#define BACKEND_ASSIGNMENTCHOICE_H

#include "Choice.h"

/**
 * The AssignmentChoice class
 * @brief this class is inherited from choice class and stores the assigned character
 */
class AssignmentChoice : public Choice {
public:
    /**
     * AssignmentChoice
     * @brief constructor with parameters
     * @param c choice
     * @param A character assignment
     */
    AssignmentChoice(const std::string & c, char A) : Choice(c), Assignment(A) {}

    /**
     * set_Assignment
     * @brief set the character assignment
     * @param a the character assignment
     */
    void set_Assignment(char a) { Assignment = a; }

    /**
     * get_Assignment
     * @brief get the character assignment
     * @return the character assignment
     */
    char get_Assignment() const { return Assignment; }

private:
    char Assignment; // Character Assignment for the choice
};

#endif //BACKEND_ASSIGNMENTCHOICE_H

