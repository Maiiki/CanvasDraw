/*****************************************************************//**
 * \file   CSquare.h
 * \brief  Class that inherits form CShape to create Rectangle Shapes
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include "CShape.h"
class CSquare :
	public CShape
{
public:
	/**
	 * Constructor that receives a position to draw a rectangle
	 * The next values are default:
	 *	- Height and Width: 100.f
	 *	- Fill Color: Red
	 *
	 * \param position Coordinates where the rectangle will be drawn
	 */
	CSquare(sf::Vector2f position);
	/**
	 * Constructor that receives position and a size to draw a rectangle
	 * The color is Red by default.
	 *
	 * \param position Coordinates where the rectangle will be drawn
	 * \param size Vector containing the height and width of the rectangle
	 */
	CSquare(sf::Vector2f position, sf::Vector2f size);
	/**
	 * Constructor that receives position, a size and a fill color to draw a rectangle
	 * 
	 * \param position Coordinates where the rectangle will be drawn
	 * \param size Vector containing the height and width of the rectangle
	 * \param fillColor Fill color for the rectangle
	 */
	CSquare(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor);

	inline void SetPosition(float x, float y)override { mRectangle.setPosition(x, y); };
	inline void SetSize(float x, float y)override { mRectangle.setSize(sf::Vector2f(x, y)); };
	inline void SetFillColor(sf::Color color)override { mRectangle.setFillColor(color); };

	inline sf::Color GetFillColor() { return mRectangle.getFillColor(); };
	inline sf::Color GetOutlineColor() { return mRectangle.getOutlineColor(); };
	inline sf::Vector2f GetPosition() { return mRectangle.getPosition(); };

	inline void Draw(sf::RenderWindow& window) override { window.draw(mRectangle); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };
	

protected:
	void ConsolePrintPoints(int index)override;
	void SavePoints()override;

protected:
	//!The rectangle shape that will serve as base for CSquare
	sf::RectangleShape mRectangle;
};

