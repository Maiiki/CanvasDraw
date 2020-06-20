#pragma once
#include "CShape.h"
class CTriangle :
	public CShape
{
public:
	CTriangle(sf::Vector2f position);
	CTriangle(sf::Vector2f position, float radius);
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

private:
	void ConsolePrintPoints(int index)override;
	sf::CircleShape mTriangle;
};

