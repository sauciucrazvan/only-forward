#pragma once

#include <iostream>
#include <string>

#include "World.h"
#include "Player.h"

class Game {
private:
    int score, level;

    Game() : score(0), level(1) {}

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

public:
    static double levelStartTime;
    
    static Game& getInstance() {
        static Game instance;
        return instance;
    }

    Player player; World world;


    Game& operator++(int);
    Game& operator--(int);
    bool operator<(int x);
    bool operator>(int x);

    /* FRIEND FUNCTIONS */
    friend Game& operator+=(Game& _game, const int _score);
    friend Game& operator-=(Game& _game, const int _score);
    friend Game& operator*=(Game& _game, const double _score);
    friend Game& operator/=(Game& _game, const double _score);

    static std::string toString(Game& _game);
    friend std::ostream& operator<<(std::ostream& o, Game& _game);
};
