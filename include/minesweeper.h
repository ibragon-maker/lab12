#ifndef ARCADE_MINESWEEPER_H
#define ARCADE_MINESWEEPER_H

#include "game.h"

int minesweeper_score(int revealed, bool won);

class Minesweeper : public Game {
public:
    Minesweeper();

    void play();
    [[nodiscard]] int times_played() const;

private:
    int m_times_played;
};

#endif 
