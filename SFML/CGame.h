/*****************************************************************//**
 * \file   CGame.h
 * \brief  Class that can be used as base to do a game from scratch.
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include <SFML/Graphics.hpp>

class CGame
{
public:
	/**
	 * Creates an single instance of the CGame class.
	 * This pattern design prevents creating more than one instance
	 * 
	 * \return A reference to a CGame class
	 */
	static CGame& instance();
	/**
	 * Gameloop. Keeps the game running and calls the main functions of the pattern:
	 *	- ProcessEvents()
	 *  - Update()
	 *  - Render()
	 * 
	 */
	void Run();

private:
	/**
	 * Constructor. Initializes multiple elements:
	 *	- Creates the window of the game.
	 *	- Initializes al the booleans (false)
	 *	- Sets the frames per seconds.
	 *	- Creates the player instance. Setting:
	 *		-#player speed
	 *		-#player radius
	 *		-#player position
	 *		-#player fill color
	 * 
	 */
	CGame();
	/**
	 * Proccess keyboard and window events.
	 * Events proccessed:
	 *	- keyboard events
	 *		-# key press event
	 *		-# key release event
	 *	- window events
	 *		-# window close event
	 */
	void ProcessEvents();
	/**
	 * Updates the game objects.
	 *	- Currently only changes the player position.
	 * 
	 * \param deltaTime Time since last frame.
	 */
	void Update(sf::Time deltaTime);
	/**
	 * Draws all the game objects.
	 *	- Currently only draws the player
	 * 
	 */
	void Render();
	/**
	 * Handles keyboard input. Currently receives the following:
	 *	- W / ArrowUp	|	Player move up
	 *	- S / ArrowDown	|	Player move down
	 *	- A / ArrowLeft	|	Player move left
	 *	- D / ArrowRight|	Player move right
	 * 
	 * \param key Value of the key pressed/released.
	 * \param isPressed Indicates if the key was pressed/released.
	 */
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	//!Instance of the window created
	sf::RenderWindow mWindow;
	//!Circle shape that represents the player
	sf::CircleShape mPlayer;
	//!Boolean tha indicates the direction the player is moving
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	//!Max speed of the player
	float mPlayerSpeed;
	//!Frames for second 
	sf::Time mTimePerFrame;
};