// Name: Lucy(Ruoshi) Huang & Naomi(Youjun) Chen
// Course: PIC 10C
// Date: 03/14/2019
// Honors Pledge: I pledge that I have neither given nor received
//                unauthorized assistance on this assignment.

#include "consequences.h"
#include <QtDebug>

Consequences::Consequences(QWidget *parent) : QWidget(parent)
{
    page_num = 0; //initialize page number to be 0
    window_stack = new QStackedWidget;
    welcome_page = new WelcomeWindow;
    gender_page = new GenderAssignment;
    character_page = new CharacterAssignment;
    end_page = new EndWindow;

    //the following are not in the stacked widget,
    //memory will be cleaned by the destructor of consequences
    fire_end_page = new fireendwindow;
    fire_game = new FireGame;
    ice_cream_game = new IceCreamGame;
    playstory = new PlayStory;
    sound_window = new SoundWindow;

    //set the background color of some windows
    fire_game->setStyleSheet("FireGame {background-color: rgb(37,37,47)}");
    fire_end_page->setStyleSheet("fireendwindow{background-color: rgb(0,0,0)}");

    //create five new pages of trinary choice window
    for(size_t i = 0; i < 5; ++i) {
        TC_page.push_back(new TrinaryChoiceWindow);
    }

    //create ten new pages of binary choice window
    for(size_t i = 0; i < 11; ++i) {
        BC_page.push_back(new BinaryChoiceWindow);
    }

    //add all windows into a stacked widget called window_stack
    window_stack->addWidget(welcome_page);
    window_stack->addWidget(gender_page);
    //add all TC pages
    for(size_t i = 0; i < TC_page.size(); ++i) {
        window_stack->addWidget(TC_page[i]);
    }
    window_stack->addWidget(character_page);
    //add all BC pages
    for(size_t i = 0; i < BC_page.size(); ++i) {
        window_stack->addWidget(BC_page[i]);
    }
    window_stack->addWidget(end_page);

    //set the welcome page as the default page
    window_stack->setCurrentIndex(0);

    //put the window_stack into the layout for this window
    layout = new QVBoxLayout;
    layout->addWidget(window_stack);
    setLayout(layout);

    //set window size
    setFixedSize(800,650);

    //setting the background image
    //source: https://freedesignfile.com/293509-pink-floral-background-hd-picture/
    QPixmap background(":/Background/PinkFloral.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    //set the background music
    //source: https://www.melodyloops.com/my-music/longoloops/moment-of-peace/
    music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Music/music.mp3"));
    music->play();

    make_connections();

    playstory->read_in_trinary_choices();
}

Consequences::~Consequences(){
    delete playstory;
    delete fire_game;
    delete ice_cream_game;
    delete fire_end_page;
    delete sound_window;
    delete music;
}

void Consequences::make_connections() {
    qDebug() << "make_connections entered";

    //The following code makes the preliminary connections needed
    //mostly page transitions within the stacked widget

    QObject::connect(sound_window->sound_on, SIGNAL(clicked()), this, SLOT(turn_on_sound()));
    QObject::connect(sound_window->sound_off, SIGNAL(clicked()), this, SLOT(turn_off_sound()));

    QObject::connect(welcome_page->start, SIGNAL(clicked()), this, SLOT(next_page()));
    QObject::connect(welcome_page->start, SIGNAL(clicked()), this, SLOT(set_tri_choice_text()));
    QObject::connect(welcome_page->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    QObject::connect(welcome_page->quit, SIGNAL(clicked()), this, SLOT(close()));


    //only one of the following will actually be used, since only one of the two buttons will be clicked
    QObject::connect(gender_page->male, SIGNAL(clicked()), this, SLOT(next_page()));
    QObject::connect(gender_page->female, SIGNAL(clicked()), this, SLOT(next_page()));
    QObject::connect(gender_page->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    QObject::connect(gender_page->quit, SIGNAL(clicked()), this, SLOT(close()));

    //make connections for all TC pages
    for (size_t i = 0; i < TC_page.size(); ++i) {
        //only one of the following will actually be used, since only one of the three buttons will be clicked
        QObject::connect(TC_page[i]->choice1, SIGNAL(clicked()), this, SLOT(next_page()));
        QObject::connect(TC_page[i]->choice1, SIGNAL(clicked()), playstory, SLOT(increment_TC_page_idx()));
        QObject::connect(TC_page[i]->choice1, SIGNAL(clicked()), this, SLOT(set_chosen_TC_choice1()));
        
        QObject::connect(TC_page[i]->choice2, SIGNAL(clicked()), this, SLOT(next_page()));
        QObject::connect(TC_page[i]->choice2, SIGNAL(clicked()), playstory, SLOT(increment_TC_page_idx()));
        QObject::connect(TC_page[i]->choice2, SIGNAL(clicked()), this, SLOT(set_chosen_TC_choice2()));
        
        QObject::connect(TC_page[i]->choice3, SIGNAL(clicked()), this, SLOT(next_page()));
        QObject::connect(TC_page[i]->choice3, SIGNAL(clicked()), playstory, SLOT(increment_TC_page_idx()));
        QObject::connect(TC_page[i]->choice3, SIGNAL(clicked()), this, SLOT(set_chosen_TC_choice3()));
        
        QObject::connect(TC_page[i]->quit, SIGNAL(clicked()), this, SLOT(close()));
        QObject::connect(TC_page[i]->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    }


    QObject::connect(character_page->next_button, SIGNAL(clicked()), this, SLOT(next_page()));
    QObject::connect(character_page->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    QObject::connect(character_page->quit, SIGNAL(clicked()), this, SLOT(close()));

    //the connections for all but the last of binary choice pages
    for(size_t i = 0; i < BC_page.size() - 1; ++i) {
        QObject::connect(BC_page[i]->choice1, SIGNAL(clicked()), this, SLOT(next_page()));
        QObject::connect(BC_page[i]->choice2, SIGNAL(clicked()), this, SLOT(next_page()));
        QObject::connect(BC_page[i]->quit, SIGNAL(clicked()), this, SLOT(close()));
        QObject::connect(BC_page[i]->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    }

    //the connections for the last binary choice page(linked to the ice cream game)
    size_t BC_last = BC_page.size() - 1;
    QObject::connect(BC_page[BC_last]->choice1, SIGNAL(clicked()), ice_cream_game, SLOT(show()));
    QObject::connect(BC_page[BC_last]->choice2, SIGNAL(clicked()), this, SLOT(next_page()));
    QObject::connect(BC_page[BC_last]->choice2, SIGNAL(clicked()), this, SLOT(fill_bad_ending()));
    QObject::connect(BC_page[BC_last]->quit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(BC_page[BC_last]->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    QObject::connect(ice_cream_game, SIGNAL(gameClosed()), this, SLOT(next_page()));
    QObject::connect(ice_cream_game, SIGNAL(gameClosed()), this, SLOT(fill_good_ending()));

    QObject::connect(this, SIGNAL(send_page_num(size_t)), this, SLOT(show_page(size_t)));

    QObject::connect(end_page->sound, SIGNAL(clicked()), sound_window, SLOT(show()));
    QObject::connect(end_page->quit, SIGNAL(clicked()), this, SLOT(close()));

    //connection to set gender
    QObject::connect(gender_page->male, SIGNAL(clicked()), playstory, SLOT(set_male()));
    QObject::connect(gender_page->female, SIGNAL(clicked()), playstory, SLOT(set_female()));

    //connection to get the personality result
    QObject::connect(this, SIGNAL(call_personality_result()), playstory, SLOT(personality_result()));

    //connections to play each round
    QObject::connect(playstory, SIGNAL(begin_round_1()), this, SLOT(connect_round1()));
    QObject::connect(playstory, SIGNAL(begin_round_2()), this, SLOT(connect_round2()));

    QObject::connect(playstory, SIGNAL(call_fill_character()), this, SLOT(fill_character_page()));

    //connection to tabulate the points for each round
    QObject::connect(playstory, SIGNAL(call_tabulate(size_t)), playstory, SLOT(tabulate_points(size_t)));

    QObject::connect(playstory, SIGNAL(open_fire_game()), fire_game, SLOT(show()));

    QObject::connect(playstory, SIGNAL(call_end_story()), this, SLOT(end_story()));
    QObject::connect(playstory, SIGNAL(call_end_story()), this, SLOT(fill_bad_ending()));

    QObject::connect(playstory, SIGNAL(call_fire_end()), fire_end_page, SLOT(show()));
    QObject::connect(playstory, SIGNAL(call_fire_end()), this, SLOT(hide()));
    QObject::connect(fire_end_page->quit, SIGNAL(clicked()), this, SLOT(close()));
}

//slot
void Consequences::connect_round1(){
    qDebug() << "connect_round 1 entered";
    playstory->prime_round1_file();
    playstory->read_all(playstory->round1_file);
    current_index = playstory->story_question.size();
    qDebug() << "connect_round1:"<< "playstory size is currently" << current_index;

    //loop to make all the binary choice connections
    for(size_t i = 0; i < current_index; ++i) {
        make_BC_connections(i);
    }
}

//slot
void Consequences::connect_round2(){
    qDebug() << "connect round 2 entered";
    char movie_char = ' ';

    //if the first choice is chosen, horror movie is chosen
    //otherwise, romance movie is chosen
    if(playstory->story_choice1[5].get_chosen()){
        qDebug() << "horror movie is chosen";
        movie_char = 'H';
    } else {
        qDebug() << "romance movie is chosen";
        movie_char = 'R';
    }

    playstory->prime_round2_file(movie_char);
    playstory->read_all(playstory->round2_file);

    size_t prev_index = current_index;
    current_index = playstory->story_question.size();
    qDebug()<<"connect_round2:"<< "prev index is" << prev_index << "current index is" << current_index;

    //make the binary choice connections for round 2
    for(size_t i = prev_index; i < current_index; ++i) {
        make_BC_connections(i);
    }
}

//private helper functions called by other connect functions
void Consequences::make_BC_connections(size_t i){
    BC_page[i]->text->setText(QString::fromStdString(playstory->story_question[i]));
    BC_page[i]->choice1->setText(QString::fromStdString(playstory->story_choice1[i].get_choice()));
    BC_page[i]->choice2->setText(QString::fromStdString(playstory->story_choice2[i].get_choice()));
    QObject::connect(BC_page[i]->choice1, SIGNAL(clicked()), playstory, SLOT(set_choice1()));
    QObject::connect(BC_page[i]->choice2, SIGNAL(clicked()), playstory, SLOT(set_choice2()));
}

//slot
void Consequences::fill_character_page(){
    //source for the character images: https://goo.gl/images/tSijqb
    //source: 123rf.com

    //fill in the character page based on the gender and personality stored in playstory
    if(playstory->get_personality() == 'A') {
        if (playstory->get_gender() == 'M'){
            QPixmap male_A(":/Avatars/maleA.png");
            character_page->character_pic->setPixmap(male_A);
            character_page->character_description->setText("Alexander\n"
                                                           "- confident, outgoing and enterprising\n"
                                                           "- a born leader\n"
                                                           "- looked upon by other for motivation and inspiration");
        } else {
            QPixmap female_A(":/Avatars/femaleA.png");
            character_page->character_pic->setPixmap(female_A);
            character_page->character_description->setText("Emily\n"
                                                           "- beautiful, fashionable and charming\n"
                                                           "- has a good sense of humor\n"
                                                           "- somewhat of a player though");
        }
    } else if (playstory->get_personality() == 'B') {
        if (playstory->get_gender() == 'M'){
            QPixmap male_B(":/Avatars/maleB.png");
            character_page->character_pic->setPixmap(male_B);
            character_page->character_description->setText("Benjamin\n"
                                                           "- an intellectual\n"
                                                           "- conciliatory and sensitive\n"
                                                           "- has an appreciation for beauty\n"
                                                           "- the \"chill dude\"");
        } else {
            QPixmap female_B(":/Avatars/femaleB.png");
            character_page->character_pic->setPixmap(female_B);
            character_page->character_description->setText("Fiona\n"
                                                           "- incredibly smart and high-achieving\n"
                                                           "- quiet until you get to know her\n"
                                                           "- is able to give an opinion on almost anything");
        }
    } else {
        if (playstory->get_gender() == 'M'){
            QPixmap male_C(":/Avatars/maleC.png");
            character_page->character_pic->setPixmap(male_C);
            character_page->character_description->setText("Carter\n"
                                                           "- intelligent and eccentric\n"
                                                           "- laid back\n"
                                                           "- somewhat enigmatic and hard to become close with");
        } else {
            QPixmap female_C(":/Avatars/femaleC.png");
            character_page->character_pic->setPixmap(female_C);
            character_page->character_description->setText("Gemma\n"
                                                           "- innocent and quirky\n"
                                                           "- enjoys unique and peculiar things\n"
                                                           "- not everyone can understand her sometimes");
        }
    }
}

//slot
void Consequences::fill_good_ending(){
    //source:https://goo.gl/images/Phz2bE
    QMovie *beatingheart = new QMovie(":/Gifs/beatingheart.gif");
    end_page->end_gif->setMovie(beatingheart);
    beatingheart->start();
    end_page->end_text->setText("Your date absolutely adored you!\nSomeone just snagged themselves a second date ;)");
}

//slot
void Consequences::fill_bad_ending(){
    //source:https://goo.gl/images/5KQ5DL
    QMovie *brokenheart = new QMovie(":/Gifs/brokenheart.gif");
    end_page->end_gif->setMovie(brokenheart);
    brokenheart->start();
    end_page->end_text->setText("Oof. Your date didn't really think you guys were compatible.\nIt's okay, many more fish in the pond!");
}

//slot
//emits the signal to trigger showing the next page in the window stack
void Consequences::next_page(){
    //send the next page number by incrementing page_num then return
    emit send_page_num(++page_num);
}

//slot
//show the page in window_stack indexed at page_num
void Consequences::show_page(size_t page_num) const{
    window_stack->setCurrentIndex(page_num);
}


// slot for sound control
void Consequences::turn_on_sound(){
    //play music (but set time restriction for multiple clicking)
    if(allow_state_change) {
        music->play();
        allow_state_change = false;
        QTimer::singleShot(1000, this, SLOT(setStateChangeToTrue()));
    }

}

//slot for sound control
void Consequences::turn_off_sound(){
    //pause music (but set time restriction for multiple clicking)
    if(allow_state_change) {
        music->pause();
        allow_state_change = false;
        QTimer::singleShot(1000, this, SLOT(setStateChangeToTrue()));
    }
}

//helper slot for sound control
void Consequences::setStateChangeToTrue(){
    allow_state_change = true;
}

//slot
void Consequences::end_story(){
    window_stack->setCurrentIndex(window_stack->indexOf(end_page));
}

void Consequences::set_tri_choice_text(){
    qDebug() << "set text for trinary choice";
    
    //set the text for all trinary choices
    for (size_t i = 0; i < TC_page.size(); ++i) {
        QString text_A = QString::fromStdString(playstory->TC_choice1[i]->get_choice());
        QString text_B = QString::fromStdString(playstory->TC_choice2[i]->get_choice());
        QString text_C = QString::fromStdString(playstory->TC_choice3[i]->get_choice());
        TC_page[i]->choice1->setText(text_A);
        TC_page[i]->choice2->setText(text_B);
        TC_page[i]->choice3->setText(text_C);
    }
}

void Consequences::set_chosen_TC_choice1(){
    playstory->TC_choice1[playstory->TC_page_idx-1]->set_chosen();
    qDebug() << QString::fromStdString( playstory->TC_choice1[playstory->TC_page_idx-1]->get_choice())
    << playstory->TC_choice1[playstory->TC_page_idx-1]->get_Assignment()
    << playstory->TC_choice1[playstory->TC_page_idx-1]->get_chosen();
    
    //when all TC choices are chosen, emit signal to get personality result
    if(playstory->TC_page_idx == TC_page.size()){
        emit call_personality_result();
    }
}
void Consequences::set_chosen_TC_choice2(){
    playstory->TC_choice2[playstory->TC_page_idx-1]->set_chosen();
    qDebug() << QString::fromStdString( playstory->TC_choice2[playstory->TC_page_idx-1]->get_choice())
    << playstory->TC_choice2[playstory->TC_page_idx-1]->get_Assignment()
    << playstory->TC_choice2[playstory->TC_page_idx-1]->get_chosen();

    //when all TC choices are chosen, emit signal to get personality result
    if(playstory->TC_page_idx == TC_page.size()){
        emit call_personality_result();
    }
};

void Consequences::set_chosen_TC_choice3(){
    playstory->TC_choice3[playstory->TC_page_idx-1]->set_chosen();
    qDebug() << QString::fromStdString( playstory->TC_choice3[playstory->TC_page_idx-1]->get_choice())
    << playstory->TC_choice3[playstory->TC_page_idx-1]->get_Assignment()
    << playstory->TC_choice3[playstory->TC_page_idx-1]->get_chosen();

    //when all TC choices are chosen, emit signal to get personality result
    if(playstory->TC_page_idx == TC_page.size()){
        emit call_personality_result();
    }
};


