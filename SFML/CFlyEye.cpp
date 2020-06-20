#include "CFlyEye.h"

CFlyEye::CFlyEye(sf::Vector2f position, int points)
{
	mCircleBase.setPointCount(points);
	mCircleBase.setRadius(50.f);
	mCircleBase.setPosition(position.x-mCircleBase.getRadius(), position.y-mCircleBase.getRadius());
	mCircleBase.setOutlineColor(sf::Color::Cyan);
	linesColor = sf::Color::Cyan;
	SavePoints();
}

CFlyEye::CFlyEye(sf::Vector2f position, int points, float radius)
{
	mCircleBase.setPointCount(points);
	mCircleBase.setRadius(radius);
	mCircleBase.setPosition(position.x-radius, position.y-radius);
	mCircleBase.setOutlineColor(sf::Color::Cyan);
	linesColor = sf::Color::Cyan;
	SavePoints();
}

CFlyEye::CFlyEye(sf::Vector2f position, int points, float radius, sf::Color linecolor)
{
	mCircleBase.setPointCount(points);
	mCircleBase.setRadius(radius);
	mCircleBase.setPosition(position.x-radius, position.y-radius);
	mCircleBase.setOutlineColor(linecolor);
	linesColor = linecolor;
	SavePoints();
}


void CFlyEye::ConsolePrintPoints(int index)
{
	for (int i = 0; i < mPoints.size(); i++)
	{
		printf("%d/t[%d]/tx: %d/ty: %d/n", index, i, mPoints[i].x, mPoints[i].y);
	}
}

void CFlyEye::SavePoints()
{
	for (int i = 0; i < mCircleBase.getPointCount(); i++)
	{
		mPoints.push_back(mCircleBase.getPoint(i));
	}
}

void CFlyEye::Draw(sf::RenderWindow& window)
{
	sf::Vertex line[2];
	for (size_t i = 0; i < mPoints.size(); i++)
	{
		for (size_t j = i; j < mPoints.size(); j++)
		{
			line[0] = sf::Vertex(mPoints[i]);
			line[1] = sf::Vertex(mPoints[j]);
			line[0].color = linesColor;
			line[1].color = linesColor;
			window.draw(line, 2, sf::Lines);
		}
	}
}

