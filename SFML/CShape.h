#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class CShape
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	
	virtual void SetPosition(float x, float y) = 0;
	virtual void SetSize(float x, float y) = 0;
	virtual void SetFillColor(sf::Color color) = 0;

	virtual sf::Color GetFillColor() = 0;
	virtual sf::Color GetOutlineColor() = 0;
	virtual sf::Vector2f GetPosition() = 0;
	virtual std::vector<sf::Vector2f> GetPoints() = 0;
	virtual void ConsolePrintPoints(int index) = 0;
	
protected:
	virtual void SavePoints() = 0;

protected:
	sf::Vector2f mSize, mPosition;
	std::vector<sf::Vector2f> mPoints;
	sf::Color fillColor;
};

