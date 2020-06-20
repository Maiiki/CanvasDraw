#pragma once
#include <SFML/Graphics.hpp>

class CGame
{
public:
	static CGame& instance();
	void Run();

private:
	CGame();
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	float mPlayerSpeed;
	sf::Time mTimePerFrame;
};