#ifndef GAME_H
#define GAME_H

#include "snake.h"

class Game {
private:
	sf::RenderWindow	_window;
	sf::Event			_event;
	bool				_pause;

	Snake				_snake;
public:
	Game();
	~Game();

	void handleEvent();
	void handleKey(uint);
	void update();
	void draw();
	void pause(bool flag = true);
	void loop();
};

#endif // GAME_H
