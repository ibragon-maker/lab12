#ifndef ARCADE_GAME_H
#define ARCADE_GAME_H

#include <string>

class Game {
public:
    explicit Game(std::string title);
    virtual ~Game() = default;

    [[nodiscard]] const std::string& title() const;
    [[nodiscard]] int last_score() const;

    void play();

protected:
    void set_score(int score);
    [[nodiscard]] bool ask_play_again() const;

private:
    std::string m_title;
    int m_last_score;
};

#endif 
