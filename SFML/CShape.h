/*****************************************************************//**
 * \file   CShape.h
 * \brief  Interface for all the shapes
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum class shapeType
{
	CIRCLE, TRIANGLE, SQUARE, FLYEYE, ISOMETRIC
};

class CShape
{
public:
	/**
	 * Draws the current shape in the referenced window
	 * 
	 * \param window Reference to the window where the shape is to draw
	 */
	virtual void Draw(sf::RenderWindow& window) = 0;
	/**
	 * Sets a new position of the current shape to the received parameters
	 * 
	 * \param x New position in x for the shape
	 * \param y New postion in y for the shape
	 */
	virtual void SetPosition(float x, float y) = 0;
	/**
	 * Sets (overwrites) a new size for the current shape
	 * 
	 * \param x The new width of the shape
	 * \param y The new height of the shape
	 */
	virtual void SetSize(float x, float y) = 0;
	/**
	 * Sets a new fill color for the shape
	 * 
	 * \param color The new color for the filler
	 */
	virtual void SetFillColor(sf::Color color) = 0;
	/**
	 * Returns the current fill color of the shape
	 * 
	 * \return Current color
	 */
	virtual sf::Color GetFillColor() = 0;
	/**
	 * Gets the current outline color of the shape
	 * 
	 * \return Current line color
	 */
	virtual sf::Color GetOutlineColor() = 0;
	/**
	 * Gets the current position of the shape
	 * 
	 * \return Current coordinates of the shape
	 */
	virtual sf::Vector2f GetPosition() = 0;
	/**
	 * Get all the points of the shape
	 * 
	 * \return std::vector of sf::Vector2f containing the coordinates of all the points in the shape.
	 */
	virtual std::vector<sf::Vector2f> GetPoints() = 0;
	/**
	 * Prints in the console all the points in the shape
	 * 
	 * \param index Number asigned to this shape by its position in the canvas.
	 */
	virtual void ConsolePrintPoints(int index) = 0;
	shapeType mType;
	
protected:
	/**
	 * Saves all the coordinates of the shape in mPoints.
	 * 
	 */
	virtual void SavePoints() = 0;

protected:
	//!sf::Vector2f used to store width and height
	sf::Vector2f mSize;
	//!sf::Vector2f used to store the coordinates of the position
	sf::Vector2f mPosition;
	//!Dynamic array of vectors containing all the points of the shape
	std::vector<sf::Vector2f> mPoints;
	//!Current fill color.
	sf::Color fillColor;
};

