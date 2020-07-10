#include "CCircle.h"

CCircle::CCircle(sf::Vector2f position)
{
	mType = shapeType::CIRCLE;
	mCircle.setRadius(50.f);
	mCircle.setPosition(position.x - mCircle.getRadius(), position.y - mCircle.getRadius());
	mCircle.setFillColor(sf::Color::Cyan);
	SavePoints();
}

CCircle::CCircle(sf::Vector2f position, float radius)
{
	mType = shapeType::CIRCLE;
	mCircle.setRadius(radius);
	mCircle.setPosition(position.x - mCircle.getRadius(), position.y - mCircle.getRadius());
	mCircle.setFillColor(sf::Color::Cyan);
	SavePoints();
}

CCircle::CCircle(sf::Vector2f position, float radius, sf::Color fillColor)
{
	mType = shapeType::CIRCLE;
	mCircle.setRadius(radius);
	mCircle.setPosition(position.x - mCircle.getRadius(), position.y - mCircle.getRadius());
	mCircle.setFillColor(fillColor);
	SavePoints();
}

void CCircle::ConsolePrintPoints(int index)
{
	for (int i = 0; i < mPoints.size(); i++)
	{
		printf("%d/t[%d]/tx: %d/ty: %d/n", index, i, mPoints[i].x, mPoints[i].y);
	}
}

void CCircle::SavePoints()
{
	for (int i = 0; i < mCircle.getPointCount(); i++)
	{
		mPoints.push_back(mCircle.getPoint(i));
	}
}
