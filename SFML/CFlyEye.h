/*****************************************************************//**
 * \file   CFlyEye.h
 * \brief  Class inherited from CShape
 * 
 * \author Miguel Gutierrez
 * \date   June 2020
 *********************************************************************/
#pragma once
#include "CShape.h"
#include <vector>

class CFlyEye :
	public CShape
{
public:
	/**
	 * Constructor that receives a position and number of points to draw a Fly Eye
	 * The next values are default:
	 *	- Radius: 50.f
	 *	- Fill Color: Cyan
	 * 
	 * \param position Coordinates where the circle will be drawn
	 * \param points Number of points tha the shape will have
	 */
	CFlyEye(sf::Vector2f position, int points);
	/**
	 * Constructor that receives position, number of points and a radius to draw a Fly Eye
	 * The color is Cyan by default.
	 * 
	 * \param position Coordinates where the circle will be drawn
	 * \param points Number of points tha the shape will have
	 * \param radius Radius of the base circle
	 */
	CFlyEye(sf::Vector2f position, int points, float radius);
	/**
	 * Constructor that receives position, number of points, radius and a line color to draw a Fly Eye
	 * 
	 * \param position Coordinates where the circle will be drawn
	 * \param points Number of points tha the shape will have
	 * \param radius Radius of the base circle
	 * \param linecolor Color of the drawn lines
	 */
	CFlyEye(sf::Vector2f position, int points, float radius, sf::Color linecolor);

	inline void SetPosition(float x, float y)override { mCircleBase.setPosition(x, y); };
	inline void SetSize(float x, float y)override { mCircleBase.setRadius(x / 2); };
	inline void SetFillColor(sf::Color color)override { mCircleBase.setFillColor(color); };
	inline void SetLinesColor(sf::Color color) { linesColor = color; };

	inline sf::Color GetFillColor() { return mCircleBase.getFillColor(); };
	inline sf::Vector2f GetPosition() { return mCircleBase.getPosition(); };
	inline sf::Color GetOutlineColor() { return mCircleBase.getOutlineColor(); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };

	void Draw(sf::RenderWindow& window)override;
	static int CheckValidPointsQtt(int qttPoints);

protected:
	void ConsolePrintPoints(int index)override;
	void SavePoints()override;

protected:
	//!Cricle that works as a base for the points tha will be conected to form the fly eye
	sf::CircleShape mCircleBase;
	//!Color of the lines drawn
	sf::Color linesColor;
};

