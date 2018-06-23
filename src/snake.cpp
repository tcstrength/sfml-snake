#include "snake.h"

sf::Texture* Snake::_nodeTxr = NULL;

Snake::Snake(sf::RenderWindow *window)
	: _window(window)
{
	if (_nodeTxr == NULL) {
		_nodeTxr = new sf::Texture();
		_nodeTxr->loadFromFile(NODE_IMG);
	}

	setDirect(DIRECTION_RIGHT);
	addNode();
	addNode();
	addNode();
}

Snake::~Snake() {
	for (auto spr : _vecSpr)
		delete spr;
	_vecSpr.clear();
}

void Snake::handleKey(uint code) {
	switch (code) {
		case sf::Keyboard::Down: setDirect(DIRECTION_DOWN); break;
		case sf::Keyboard::Up: setDirect(DIRECTION_UP); break;
		case sf::Keyboard::Left: setDirect(DIRECTION_LEFT); break;
		case sf::Keyboard::Right: setDirect(DIRECTION_RIGHT); break;
		case sf::Keyboard::Space: addNode(); break;
		case sf::Keyboard::S: speed(60); break;
		default: break;
	}
}

void Snake::update() {
	static uint ticks = 0;
	uint snakeSize = _vecSpr.size();

	if (snakeSize == 0)
		return;

	if (++ticks <= _ticks)
		return;

	for (uint i = snakeSize - 1; i >= 1; --i)
		_vecSpr[i]->setPosition(_vecSpr[i - 1]->getPosition());

	auto front = _vecSpr.front();
	front->setPosition(front->getPosition() + _dVec);

	ticks = 0;
}

void Snake::draw() {
	for (auto spr : _vecSpr)
		_window->draw(*spr);
}

void Snake::addNode() {
	if (_vecSpr.size() == 0) {
		_vecSpr.push_back(new sf::Sprite(*Snake::_nodeTxr, TXR_RECT));
		_vecSpr.front()->setPosition(START_LOC);
		return;
	}

	sf::Vector2f pos = _vecSpr.back()->getPosition();

	_vecSpr.push_back(new sf::Sprite(*Snake::_nodeTxr, TXR_RECT));
	_vecSpr.back()->setPosition(pos - _dVec);
}

void Snake::setDirect(uint direct) {
	static uint oldDirect = -1;

	if (oldDirect == DIRECTION_LEFT && direct == DIRECTION_RIGHT)
		return;
	if (oldDirect == DIRECTION_RIGHT && direct == DIRECTION_LEFT)
		return;
	if (oldDirect == DIRECTION_UP && direct == DIRECTION_DOWN)
		return;
	if (oldDirect == DIRECTION_DOWN && direct == DIRECTION_UP)
		return;
	if (oldDirect == direct)
		return;

	oldDirect = direct;

	switch (direct) {
		case DIRECTION_LEFT: _dVec = {-26, 0}; break;
		case DIRECTION_RIGHT: _dVec = {+26, 0}; break;
		case DIRECTION_UP: _dVec = {0, -26}; break;
		case DIRECTION_DOWN: _dVec = {0, +26}; break;
		default: break;
	}

	// #FIXME
	update();
}
