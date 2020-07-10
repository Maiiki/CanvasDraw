/*****************************************************************//**
 * \file   CCanvas.h
 * \brief  Class of the main instance for the running programm
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include "CCircle.h"
#include "CTriangle.h"
#include "CSquare.h"
#include "CFlyEye.h"
#include "CIsometricShape.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class CCanvas
{
public:
	/**
	 * Creates and single instance of the canvas
	 * 
	 * \return CCanvas reference
	 */
	static CCanvas& instance();
	/**
	 * Gameloop pattern. Keeps the programm running..
	 */
	void Run();

protected:
	/**
	 * Constructor. Sets the window size, window title and initializes variables.
	 */
	CCanvas();
	/**
	 * Proccess mouse, keyboard and window events.
	 */
	void ProcessEvents();
	/**
	 * Handles keyboard input.
	 * 
	 * \param key Value of the pressed/released key.
	 * \param isPressed Indicates if the key is pressed or released.
	 */
	void HandleInput(sf::Keyboard::Key key, bool isPressed);
	/**
	 * Handles mouse input.
	 * 
	 * \param btn Value of the mouse button that was pressed.
	 * \param x Coordinate in x of the mouse position.
	 * \param y Coordinate in y of the mouse position.
	 */
	void HandleInput(sf::Mouse::Button btn, int x, int y);
	/**
	 * Updates all the elements in the canvas and adds new ones (if any).
	 * 
	 * \param deltaTime Time transcurred since last frame.
	 */
	void Update(sf::Time deltaTime);
	/**
	 * Draw in the canvas all the shapes contained in allShapes.
	 * 
	 */
	void Render();
	/**
	 * Prints in the console the coordinates of the points of all shapes.
	 * 
	 */
	void ConsolePrintShapesPoints();

protected:
	//!Angle to rotate the shapes in isometric.
	float rotateAngle;
	//!Window reference
	sf::RenderWindow mWindow;
	//!Fixed number of frames per second that the programm will be updated
	sf::Time mFramesPerSeconds;
	//!Boolean to know wich shape is going to be drawn.
	bool mbCircle, mbTriangle, mbSquare, mbFlyEye;
	//!Boolean that sets the angle of the shapes to isometric.
	bool mbIsometric;
	//!Boolean that indicates if the user can draw.
	bool mbDrawing;
	//!Boolean that indicates if the shape list has to be cleared.
	bool mbErase;
	//!Boolean that indicates if the last shape in the list has to be erased.
	bool mbUndo;
	//!Vector containing all the drawn shapes.
	std::vector<CShape*> allShapes;
	//!Vector containing the points of the shapes rotated the angle indicated in angleRotate.
	std::vector<CShape*>rotatedShapes;
	//!Position of the mouse click
	sf::Vector2i drawPosition;
};
