#ifndef ARCADE_HANGMAN_H
#define ARCADE_HANGMAN_H

#include "game.h"
#include <string>

class Hangman : public Game {
public:
    Hangman();

    void play();
    [[nodiscard]] int times_played() const;

private:
    int m_times_played;
};

#endif 
