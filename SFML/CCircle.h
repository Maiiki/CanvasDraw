/*****************************************************************//**
 * \file   CCircle.h
 * \brief  Class inherited from CShape used to draw circles.
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include "CShape.h"
class CCircle :
	public CShape
{
public:
	/**
	 * Constructor that receives a position to draw a circle
	 * The next values are default:
	 *	- Radius: 50.f
	 *	- Fill Color: Cyan
	 * 
	 * \param position Coordinates where the circle will be drawn
	 */
	CCircle(sf::Vector2f position);
	/**
	 * Constructor that receives position and a radius to draw a circle
	 * The color is Cyan by default.
	 * 
	 * \param position Coordinates where the circle will be drawn
	 * \param radius Radius of the circle
	 */
	CCircle(sf::Vector2f position, float radius);
	/**
	 * Constructor that receives a position, a radius and a fill color to draw a circle
	 * 
	 * \param position Coordinates where the circle will be drawn
	 * \param radius Radius of the circle
	 * \param fillColor Fill color for the circle
	 */
	CCircle(sf::Vector2f position, float radius, sf::Color fillColor);
	
	inline void SetPosition(float x, float y)override { mCircle.setPosition(x, y); };
	inline void SetSize(float x, float y)override{ mCircle.setRadius(x / 2); };
	inline void SetFillColor(sf::Color color)override{ mCircle.setFillColor(color); };
	
	inline sf::Color GetFillColor() { return mCircle.getFillColor(); };
	inline sf::Vector2f GetPosition() { return mCircle.getPosition(); };
	inline sf::Color GetOutlineColor() { return mCircle.getOutlineColor(); };
	
	inline void Draw(sf::RenderWindow& window) override{ window.draw(mCircle); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };

protected:
	void ConsolePrintPoints(int index)override;
	void SavePoints()override;

protected:
	//!Circle shape member of the class.
	sf::CircleShape mCircle;
};

