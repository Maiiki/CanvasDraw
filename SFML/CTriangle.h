/*****************************************************************//**
 * \file   CTriangle.h
 * \brief  Class inherited from CShape that draws a triangle 
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include "CShape.h"
class CTriangle :
	public CShape
{
public:
	/**
	 * Constructor that receives a position to draw a triangle
	 * The next values are default:
	 *	- Height: 50.f
	 *	- Fill Color: Yellow
	 *
	 * \param position Coordinates where the center of triangle will be
	 */
	CTriangle(sf::Vector2f position);
	/**
	 * Constructor that receives position and a radius to draw a triangle
	 * The color is Yellow by default.
	 *
	 * \param position Coordinates where the center of triangle will be
	 * \param radius Height of the triangle
	 */
	CTriangle(sf::Vector2f position, float radius);
	/**
	 * Constructor that receives a position, a radius and a fill color to draw a triangle
	 *
	 * \param position Coordinates where the center of triangle will be
	 * \param radius Height of the triangle
	 * \param fillColor Fill color for the triangle
	 */
	CTriangle(sf::Vector2f position, float radius, sf::Color fillColor);
	
	inline void SetPosition(float x, float y)override { mTriangle.setPosition(x, y); };
	inline void SetSize(float x, float y)override { mTriangle.setRadius(x / 2); };
	inline void SetFillColor(sf::Color color)override { mTriangle.setFillColor(color); };

	inline sf::Color GetFillColor() { return mTriangle.getFillColor(); };
	inline sf::Color GetOutlineColor() { return mTriangle.getOutlineColor(); };
	inline sf::Vector2f GetPosition() { return mTriangle.getPosition(); };

	inline void Draw(sf::RenderWindow& window) override { window.draw(mTriangle); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };
	void SavePoints()override;

protected:
	void ConsolePrintPoints(int index)override;
	sf::CircleShape mTriangle;
};

