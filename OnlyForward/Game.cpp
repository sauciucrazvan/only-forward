#include "Game.h"
#include "UI.h"

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

std::string Game::toString(Game& _game) {
    return "Score: " + std::to_string(_game.score) + "\nLevel: #" + std::to_string(_game.level) + "\nPress R to restart";
}

std::ostream& operator<<(std::ostream& o, Game& _game) { // used
    o << Game::toString(_game) << std::endl;
    return o;
}
