#pragma once
#include <iostream>

#include "World.h"
#include "Player.h"

class Game
{
public:
	int score;
	World world; Player player;

	Game();

	Game operator++();
	Game operator--();

	friend Game& operator+=(Game& _game, const int _score);
	friend Game& operator-=(Game& _game, const int _score);
	friend Game& operator*=(Game& _game, const int _score);
	friend Game& operator/=(Game& _game, const int _score);

	friend std::ostream& operator<<(std::ostream& o, Game& _game);

	static std::string toString(Game& _game);
};

