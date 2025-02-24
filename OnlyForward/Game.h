#pragma once

#include <iostream>
#include <string>

#include "World.h"
#include "Player.h"

class Game {
private:
    int score;

    Game() : score(0) {}

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

public:
    
    static Game& getInstance() {
        static Game instance;
        return instance;
    }

    Player player; World world;


    Game& operator++();
    Game& operator--();

    /* FRIEND FUNCTIONS */
    friend Game& operator+=(Game& _game, const int _score);
    friend Game& operator-=(Game& _game, const int _score);
    friend Game& operator*=(Game& _game, const int _score);
    friend Game& operator/=(Game& _game, const int _score);

    static std::string toString(Game& _game);
    friend std::ostream& operator<<(std::ostream& o, Game& _game);
};
