#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
#define DIRECTION_UP 2
#define DIRECTION_DOWN 3
#define MAX_SPEED 64
#define NODE_IMG "png/node.png"
#define FOOD_IMG "png/food.png"
#define START_LOC {260, 260}
#define TXR_RECT {0, 0, 26, 26}
class Snake {
private:
	static sf::Texture*			_nodeTxr;
	uint						_ticks;
	sf::RenderWindow*			_window;
	sf::Vector2f				_dVec;
	std::vector<sf::Sprite*>	_vecSpr;
public:
	Snake(sf::RenderWindow* _window);
	~Snake();
	void handleKey(uint code);
	void update();
	void draw();

	void addNode();
	void setDirect(uint direct);
	void speed(uint spd) { _ticks = MAX_SPEED - spd; }
};

#endif // SNAKE_H
