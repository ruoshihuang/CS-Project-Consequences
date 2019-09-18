// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "playstory.h"
#include <iostream>
#include <QtDebug>
#include <QDir>
#include <QString>

PlayStory::PlayStory(QObject *parent) : QObject(parent)
{
    qDebug()<< gender;
    qDebug()<< personality;
}

//read in one set of question and choices
bool PlayStory::read(std::ifstream &input_file) {
    qDebug() << "enter read";
    std::string question;
    getline(input_file, question);

    //if there are no more data to read in, return false
    if(question.empty()) {
        return false;
    }
    story_question.push_back(question);

    std::string choice1;
    getline(input_file, choice1);
    std::string choice2;
    getline(input_file, choice2);

    StoryChoice temp_choice1;
    //position of '+' in choice 1, also equals length of the substring before '+'
    size_t pos1 = choice1.find('+');
    temp_choice1.set_choice(choice1.substr(0, pos1));
    temp_choice1.set_points(std::stoi(choice1.substr(pos1 + 1, 1)));

    //if the points stored is 0, it indicates that choice is meant to end the story
    if (temp_choice1.get_points() == 0){
        temp_choice1.set_end();
    }
    story_choice1.push_back(temp_choice1);

    StoryChoice temp_choice2;
    size_t pos2 = choice2.find('+');
    temp_choice2.set_choice(choice2.substr(0, pos2));
    temp_choice2.set_points(std::stoi(choice2.substr(pos2 + 1, 1)));

    //if the points stored is 0, it indicates that choice is meant to end the story
    if(temp_choice2.get_points() == 0) {
        temp_choice2.set_end();
    }
    story_choice2.push_back(temp_choice2);

    return true;
}

void PlayStory::tabulate_points(size_t start_index) {
    int points = 0;
    //tabulate the points for all chosen choices
    for(size_t i = start_index; i < story_choice1.size(); ++i) {
        //tabulate all chosen choice 1s
        if (story_choice1[i].get_chosen()) {
            points += story_choice1[i].get_points();
            //if the trigger choice is chosen, signal to call death by fire ending
            if (story_choice1[i].get_end()) {
                end_of_story = true;
                emit call_fire_end();
                qDebug() <<"fire end story is called";
            }
        }
        //tabulate all chosen choice 2s
        if (story_choice2[i].get_chosen()) {
            points += story_choice2[i].get_points();
            //if the trigger choice is chosen, signal to call death by fire ending
            if (story_choice2[i].get_end()) {
                end_of_story = true;
                emit call_fire_end();
                qDebug() <<"fire end story is called";
            }
        }
    }
    this_round_points = points;

    //if points less than 9 for round 1, or 6 for round 2,
    //game ends: broken heart ending is called
    if(start_index == 0) {
        if(this_round_points < 9) {
            end_of_story = true;
            emit call_end_story();
            qDebug() <<"broken heart end story is called";
        } else if (!end_of_story){
            emit open_fire_game();
        }
    } else if(start_index == 6 && this_round_points < 6){
        end_of_story = true;
        emit call_end_story();
        qDebug() <<"broken heart end story is called";
    }
    qDebug() << "this round you got: " << this_round_points << " points";  
}

void PlayStory::read_all(const std::string &file_name){
    qDebug() << "read_all entered";
    qDebug() << QString::fromStdString(file_name);
    std::ifstream input_file;
    input_file.open(file_name);

    //throw error if file cannot be opened
    if(input_file.fail()) {
        throw std::runtime_error("Cannot open input file");
    }

    //read in all question and choices sets
    while(read(input_file)) {}

    input_file.close();
}

void PlayStory::prime_round1_file(){    

    //prime the file name for round 1 based on the personality choice
    if (personality == 'A') {
        qDebug() << "A: if statement entered";
        round1_file = DIRECTORY + "/A1.txt";
    } else if (personality == 'B') {
        qDebug() << "B: if statement entered";
        round1_file = DIRECTORY+ "/B1.txt";
    } else if (personality == 'C') {
        qDebug() << "C: if statement entered";
        round1_file = DIRECTORY+ "/C1.txt";
    }
}

void PlayStory::prime_round2_file(char movie_choice){

    //prime the file name for round 2 based on gender and movie choice
    if (gender == 'F') {
        qDebug() << "gender F if statement entered";
        if(movie_choice == 'H') {
            qDebug()<< "Horror if statement entered";
            round2_file = DIRECTORY+ "/HorrorF.txt";
        } else if (movie_choice == 'R') {
            qDebug()<< "Romance if statement entered";
            round2_file = DIRECTORY+ "/RomanceF.txt";
        }
    } else if (gender == 'M') {
        qDebug() << "gender M if statement entered";
        if(movie_choice == 'H') {
            qDebug()<< "Horror if statement entered";
            round2_file = DIRECTORY+ "/HorrorM.txt";
        } else if (movie_choice == 'R') {
            qDebug()<< "Romance if statement entered";
            round2_file = DIRECTORY+ "/RomanceM.txt";
        }
    }
}

char PlayStory::get_personality(){
    return personality;
}

char PlayStory::get_gender(){
    return gender;
}


//slot:checked
void PlayStory::set_male() {
    gender = 'M';
    qDebug() << "gender set to: " << gender;
}

//slot: checked
void PlayStory::set_female() {
    gender = 'F';
    qDebug() <<"gender set to: " << gender;
}

//slot
void PlayStory::set_personality(char p){
    personality = p;
    qDebug() << "round 1 has begun, personality is"<< personality;
    emit call_fill_character(); //signal to fill the character page
    emit begin_round_1(); //once personality is set, begin round 1
}

//slot: checked
void PlayStory::set_choice1(){
    story_choice1[BC_index].set_chosen();
    qDebug() << BC_index << story_choice1[BC_index].get_chosen();

    //last choice of round 1 has been chosen, signal to tabulate points
    if(BC_index == 4) {
        emit call_tabulate(0);
        qDebug() << "tabulate points has been called";
    }

    //this means a movie was chosen, signal round 2 to begin
    if(BC_index == 5) {
        emit begin_round_2();
        qDebug() << "round 2 has begun";
    }

    //last choice of round 2 has been chosen, signal to tabulate points
    if(BC_index == 9){
        emit call_tabulate(6);
        qDebug() << "tabulate points has been called";
    }
    ++BC_index; //facilitate selection for the next binary choice
}

//slot: checked
void PlayStory::set_choice2(){
    story_choice2[BC_index].set_chosen();
    qDebug()<< BC_index << story_choice2[BC_index].get_chosen();

    //last choice of round 1 has been chosen, signal to tabulate points
    if(BC_index == 4) {
        emit call_tabulate(0);
        qDebug() << "tabulate points has been called";
    }

    //this means a movie was chosen, signal round 2 to begin
    if(BC_index == 5) {
        emit begin_round_2();
        qDebug() << "round 2 has begun";
    }

    //last choice of round 2 has been chosen, signal to tabulate points
    if(BC_index == 9){
        emit call_tabulate(6);
        qDebug() << "tabulate points has been called";
    }
    ++BC_index;
}

void PlayStory::read_in_trinary_choices()
{
    qDebug() << "read_in_trinary_choices() entered";
    std::fstream inputFile;
    // Open the input file
    std::string inputFileName = DIRECTORY + "/trinaryChoice.txt";
    qDebug() << QString::fromStdString(inputFileName);
    inputFile.open(inputFileName);
    
    //make actions if file is opened
    if (inputFile.is_open()){
        std::string choice_buffer = "";
        std::string assignment_buffer = " ";
        
        // read in the trinary choice
        while (std::getline(inputFile, choice_buffer, '(')) {
            //strip the '\n' character
            if(choice_buffer[0] == '\n') {choice_buffer.erase(0,1);}

            std::getline(inputFile, assignment_buffer, ')'); // read in the assignment
            inputFile.ignore(); // ignore ','
            inputFile.ignore(); // ignore ' '
            
            //check that the buffer is not empty, and then add it to the TC_choices vector
            if(choice_buffer != " " && assignment_buffer !=" "){
                TC_choices.push_back(new AssignmentChoice(choice_buffer, assignment_buffer[0]));
                qDebug() << QString::fromStdString(choice_buffer + assignment_buffer);
            }
            //clean up
            choice_buffer = "";
            assignment_buffer = " ";
        }
        
        //split the vector TC_choices into three according vectors
        for(size_t i = 0; i < TC_choices.size(); ++i){
            if(i%3 == 0) TC_choice1.push_back(TC_choices[i]);//036
            if(i%3 == 1) TC_choice2.push_back(TC_choices[i]);//147
            if(i%3 == 2) TC_choice3.push_back(TC_choices[i]);//258
        }
        
        qDebug() << "choice1:";
        for(size_t k = 0; k < TC_choice1.size(); ++k)
            qDebug() << QString::fromStdString(TC_choice1[k]->get_choice()) << TC_choice1[k]->get_Assignment();
        qDebug() << "choice2:";
        for(size_t k = 0; k < TC_choice1.size(); ++k)
            qDebug() << QString::fromStdString(TC_choice2[k]->get_choice()) << TC_choice2[k]->get_Assignment();
        qDebug() << "choice3:";
        for(size_t k = 0; k < TC_choice1.size(); ++k)
            qDebug() << QString::fromStdString(TC_choice3[k]->get_choice()) << TC_choice3[k]->get_Assignment();
        
        inputFile.close();
    } else
        qDebug() << "Error opening the input file";
}

void PlayStory::find_max_char() {
    qDebug() << "Enter the find_max_char function";
    
    //increment the counter according to the choice
    for(size_t i = 0; i < TC_choices.size(); ++i){
        if(TC_choices[i]->get_chosen() == true){
            if(TC_choices[i]->get_Assignment() == 'A') ++counter['A'];
            if(TC_choices[i]->get_Assignment() == 'B') ++counter['B'];
            if(TC_choices[i]->get_Assignment() == 'C') ++counter['C'];
        }
    }
    qDebug() << counter['A'] << counter['B'] << counter['C'];

    int max_count = 0;
    char max_char = ' ';

    // find the max character
    for (const auto & it : counter) {
        if (it.second > max_count) {
            max_count = it.second;
            max_char = it.first;
        }
    }
    set_personality(max_char);
}

//slot
void PlayStory::increment_TC_page_idx(){
    TC_page_idx++;
    qDebug() << "TC page index:" + QString::number(TC_page_idx);
}

//slot
void PlayStory::personality_result(){
    find_max_char();
}
