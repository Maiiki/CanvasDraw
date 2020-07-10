#include "CTriangle.h"

CTriangle::CTriangle(sf::Vector2f position)
{
	mType = shapeType::TRIANGLE;
	mTriangle.setPointCount(3);
	mTriangle.setRadius(50.f);
	mTriangle.setPosition(position.x - mTriangle.getRadius(), position.y - mTriangle.getRadius());
	mTriangle.setFillColor(sf::Color::Yellow);
	
}

CTriangle::CTriangle(sf::Vector2f position, float radius)
{
	mType = shapeType::TRIANGLE;
	mTriangle.setPointCount(3);
	mTriangle.setRadius(radius);
	mTriangle.setPosition(position.x - mTriangle.getRadius(), position.y - mTriangle.getRadius());
	mTriangle.setFillColor(sf::Color::Yellow);
}

CTriangle::CTriangle(sf::Vector2f position, float radius, sf::Color fillColor)
{
	mType = shapeType::TRIANGLE;
	mTriangle.setPointCount(3);
	mTriangle.setRadius(radius);
	mTriangle.setPosition(position.x - mTriangle.getRadius(), position.y - mTriangle.getRadius());
	mTriangle.setFillColor(fillColor);
}

void CTriangle::SavePoints()
{
	for (int i = 0; i < mTriangle.getPointCount(); i++)
	{
		mPoints.push_back(mTriangle.getPoint(i));
	}
}

void CTriangle::ConsolePrintPoints(int index)
{
	for (int i = 0; i < mPoints.size(); i++)
	{
		printf("%d/t[%d]/tx: %d/ty: %d/n", index, i, mPoints[i].x, mPoints[i].y);
	}
}
