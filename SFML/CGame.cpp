#include "CGame.h"
constexpr auto player_speed = 1000.f;

CGame& CGame::instance()
{
	static CGame* instance = new CGame();
	return *instance;
}

CGame::CGame()
	:mWindow(sf::VideoMode(640,480),"SFML Game"),
	mPlayer(),
	mIsMovingUp(false),
	mIsMovingDown(false),
	mIsMovingRight(false),
	mIsMovingLeft(false),
	mPlayerSpeed(player_speed),
	mTimePerFrame(sf::seconds(1.f/60.f))
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}


void CGame::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate>mTimePerFrame)
		{
			timeSinceLastUpdate -= mTimePerFrame;
			ProcessEvents();
			Update(mTimePerFrame);
		}
		Render();
	}
}

void CGame::ProcessEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void CGame::Update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp) { movement.y -= mPlayerSpeed; }
	if (mIsMovingDown) { movement.y += mPlayerSpeed; }
	if (mIsMovingLeft) { movement.x -= mPlayerSpeed; }
	if (mIsMovingRight) { movement.x += mPlayerSpeed; }

	mPlayer.move(movement * deltaTime.asSeconds());
}

void CGame::Render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void CGame::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W||key==sf::Keyboard::Up) { mIsMovingUp = isPressed; }
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down) { mIsMovingDown = isPressed; }
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left) { mIsMovingLeft = isPressed; }
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right) { mIsMovingRight = isPressed; }
}
