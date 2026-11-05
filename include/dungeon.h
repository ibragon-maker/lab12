#ifndef ARCADE_DUNGEON_H
#define ARCADE_DUNGEON_H

#include "game.h"

class Dungeon : public Game {
public:
    Dungeon();

    void play();
    [[nodiscard]] int times_played() const;

private:
    int m_times_played;
};

#endif 
