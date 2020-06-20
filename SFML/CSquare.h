#pragma once
#include "CShape.h"
class CSquare :
	public CShape
{
public:
	CSquare(sf::Vector2f position);
	CSquare(sf::Vector2f position, sf::Vector2f size);
	CSquare(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor);

	inline void SetPosition(float x, float y)override { mRectangle.setPosition(x, y); };
	inline void SetSize(float x, float y)override { mRectangle.setSize(sf::Vector2f(x, y)); };
	inline void SetFillColor(sf::Color color)override { mRectangle.setFillColor(color); };

	inline sf::Color GetFillColor() { return mRectangle.getFillColor(); };
	inline sf::Color GetOutlineColor() { return mRectangle.getOutlineColor(); };
	inline sf::Vector2f GetPosition() { return mRectangle.getPosition(); };

	inline void Draw(sf::RenderWindow& window) override { window.draw(mRectangle); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };
	

private:
	void ConsolePrintPoints(int index)override;
	void SavePoints()override;

private:
	sf::RectangleShape mRectangle;
};

