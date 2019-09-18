// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#ifndef STORYLINE_CHOICE_H
#define STORYLINE_CHOICE_H

#include <string>

/**
 * The Choice class
 * @brief this class stores the text of the choices and includes a variable that
 *        indicates if the choice is chosen
 */
class Choice {
public:
    /**
     * Default Constructor
     */
    Choice(){}

    /**
     * Choice
     * @brief Constructor with parameters
     * @param choice
     */
    Choice(const std::string& choice) : choice(choice) {}

    /**
     * set_choice
     * @brief set the choice variable
     * @param c
     */
    void set_choice(const std::string& c) { choice = c; }

    /**
     * get_choice
     * @brief get the choice variable
     * @return a string variable stored in choice
     */
    std::string get_choice() const { return choice; }

    /**
     * set_chosen
     * @brief set the variable chosen to true
     */
    void set_chosen() { chosen = true; }

    /**
     * set_not_chosen
     * @brief set the variable chosen to true
     */
    void set_not_chosen() { chosen = false; }

    /**
     * get_chosen
     * @brief get the chosen variable
     * @return a boolean value stored in chosen
     */
    bool get_chosen() const { return chosen; }

private:
    std::string choice;  // the data in the choice
    bool chosen = false; // check if it is chosen or not
};

#endif //STORYLINE_CHOICE_H
