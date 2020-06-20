#pragma once
#include "CShape.h"
class CCircle :
	public CShape
{
public:
	CCircle(sf::Vector2f position);
	CCircle(sf::Vector2f position, float radius);
	CCircle(sf::Vector2f position, float radius, sf::Color fillColor);
	
	inline void SetPosition(float x, float y)override { mCircle.setPosition(x, y); };
	inline void SetSize(float x, float y)override{ mCircle.setRadius(x / 2); };
	inline void SetFillColor(sf::Color color)override{ mCircle.setFillColor(color); };
	
	inline sf::Color GetFillColor() { return mCircle.getFillColor(); };
	inline sf::Vector2f GetPosition() { return mCircle.getPosition(); };
	inline sf::Color GetOutlineColor() { return mCircle.getOutlineColor(); };
	
	inline void Draw(sf::RenderWindow& window) override{ window.draw(mCircle); };
	inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };

private:
	void ConsolePrintPoints(int index)override;
	void SavePoints()override;

private:
	sf::CircleShape mCircle;
};

