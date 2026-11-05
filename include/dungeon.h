#ifndef ARCADE_DUNGEON_H
#define ARCADE_DUNGEON_H

#include "game.h"
#include "direction.h"
#include "room.h"

/// @file dungeon.h
/// @brief The Dungeon game: six rooms, items, a trap, and text commands.

/// Link two rooms in both directions.
void connect_rooms(Room &a, Direction d, Room &b);

/// The score for a Dungeon run.
int dungeon_score(int items_collected, int health);

class Dungeon : public Game {
public:
    Dungeon();

    void play();
    [[nodiscard]] int times_played() const;

private:
    int m_times_played;
};

#endif // ARCADE_DUNGEON_H
