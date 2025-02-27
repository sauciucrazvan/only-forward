#include "Game.h"

Game& Game::operator++(int) {
    this->level++;
    return *this;
}

Game& Game::operator--(int) {
    this->level--;
    return *this;
}

/* FRIEND FUNCTIONS */
Game& operator+=(Game& _game, const int _score) {
    _game.score += _score;
    return _game;
}

Game& operator-=(Game& _game, const int _score) {
    _game.score -= _score;
    return _game;
}

Game& operator*=(Game& _game, const int _score) {
    _game.score *= _score;
    return _game;
}

Game& operator/=(Game& _game, const int _score) {
    _game.score /= _score;
    return _game;
}

std::string Game::toString(Game& _game) {
    return "Score: " + std::to_string(_game.score) + "\nLevel: " + std::to_string(_game.level);
}

std::ostream& operator<<(std::ostream& o, Game& _game) {
    o << Game::toString(_game) << std::endl;
    return o;
}
