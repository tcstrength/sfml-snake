#include "game.h"

Game::Game()
	: _window(sf::VideoMode(640, 480), "Snake - SFML")
	, _pause(false)
	, _snake(&_window)
{
	_snake.speed(48);
	_window.setFramerateLimit(120);
}

Game::~Game() {

}

void Game::loop() {
	while (_window.isOpen()) {
		handleEvent();

		if (!_pause)
			update();

		draw();
	}
}

void Game::pause(bool flag) {
	_pause = flag;
}

void Game::handleKey(uint code) {
	_snake.handleKey(code);
}

void Game::handleEvent() {
	_window.pollEvent(_event);

	switch(_event.type) {
		case sf::Event::Closed:	_window.close(); break;
		case sf::Event::KeyPressed:	handleKey(_event.key.code);	break;
		default: break;
	}
}

void Game::draw() {
	_window.clear();

	_snake.draw();

	_window.display();
}

void Game::update() {
	_snake.update();
}
