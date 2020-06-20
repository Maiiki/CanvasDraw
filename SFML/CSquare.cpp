#include "CSquare.h"

/*///////////////////////////////////*/
/*------------Constructors-----------*/
/*///////////////////////////////////*/
CSquare::CSquare(sf::Vector2f position)
{
	mRectangle.setSize(sf::Vector2f(100.f, 100.f));
	mRectangle.setPosition(position.x - (mRectangle.getSize().x / 2), position.y - (mRectangle.getSize().y / 2));
	mRectangle.setFillColor(sf::Color::Red);
	SavePoints();
}

CSquare::CSquare(sf::Vector2f position, sf::Vector2f size)
{
	mRectangle.setSize(sf::Vector2f(size.x, size.y));
	mRectangle.setPosition(position.x - (mRectangle.getSize().x / 2), position.y - (mRectangle.getSize().y / 2));
	mRectangle.setFillColor(sf::Color::Red);
	SavePoints();
}

CSquare::CSquare(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor)
{
	mRectangle.setSize(sf::Vector2f(size.x, size.y));
	mRectangle.setPosition(position.x - (mRectangle.getSize().x / 2), position.y - (mRectangle.getSize().y / 2));
	mRectangle.setFillColor(fillColor);
	SavePoints();
}

void CSquare::ConsolePrintPoints(int index)
{
	for (int i = 0; i < mPoints.size(); i++)
	{
		printf("%d/t[%d]/tx: %d/ty: %d/n", index, i, mPoints[i].x, mPoints[i].y);
	}
}

void CSquare::SavePoints()
{
	for (int i = 0; i < mRectangle.getPointCount(); i++)
	{
		mPoints.push_back(mRectangle.getPoint(i));
	}
}
