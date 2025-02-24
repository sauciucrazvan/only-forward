#include "Game.h"

#include <iostream>
#include <string>

Game::Game() {
	this->score = 0;
}

Game Game::operator++() {
	this->score++;
	return *this;
}

Game Game::operator--() {
	this->score--;
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
	return "Score: " + std::to_string(_game.score);
}

std::ostream& operator<<(std::ostream& o, Game& _game) {
	o << Game::toString(_game) << std::endl;
	return o;
}