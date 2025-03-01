#include "Game.h"
#include "UI.h"

double Game::levelStartTime = 0;

Game& Game::operator++(int) { //used
    this->level++;
    return *this;
}

Game& Game::operator--(int) {
    this->level--;
    return *this;
}

bool Game::operator<(int x) { //used
    return this->score < x;
}

bool Game::operator>(int x) {
    return this->score > x;
}

int Game::getLevel() {
    return this->level;
}

/* FRIEND FUNCTIONS */
Game& operator+=(Game& _game, const int _score) { //used
    _game.score += _score;
    return _game;
}

Game& operator-=(Game& _game, const int _score) { // used
    _game.score -= _score;
    return _game;
}

Game& operator*=(Game& _game, const double _score) {
    _game.score *= _score;
    return _game;
}

Game& operator/=(Game& _game, const double _score) {
    _game.score /= _score;
    return _game;
}

std::string Game::toString() {
    return "Score: " + std::to_string(this->score) + "\nLevel: #" + std::to_string(this->level) + "\nPress R to restart";
}

std::ostream& operator<<(std::ostream& o, Game& _game) { // used
    o << _game.toString() << std::endl;
    return o;
}
