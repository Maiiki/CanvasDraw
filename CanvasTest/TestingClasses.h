#pragma once
#include <SFML/Graphics.hpp>
#include "../SFML/CCanvas.cpp"
#include "../SFML/CCircle.cpp"
#include "../SFML/CTriangle.cpp"
#include "../SFML/CSquare.cpp"
#include "../SFML/CFlyEye.cpp"
#include "../SFML/CIsometricShape.cpp"

class TestCCanvas :public CCanvas
{
public:
	float rotateAngle;
	sf::RenderWindow mWindow;
	sf::Time mFramesPerSeconds;
	bool mbCircle, mbTriangle, mbSquare, mbFlyEye;
	bool mbIsometric;
	bool mbDrawing;
	bool mbErase;
	bool mbUndo;
	std::vector<CShape*> allShapes;
	std::vector<CShape*>rotatedShapes;
	sf::Vector2i drawPosition;
};

class TestCTriangle :public CTriangle
{
public:
	sf::CircleShape mTriangle;
};

class TestCSquare :public CSquare
{
public:
	sf::RectangleShape mRectangle;
};

class TestCIsometricShape :public CRotateShape
{
public:
	sf::ConvexShape mShape;
};

class TestCFlyEye :public CFlyEye
{
public:
	sf::CircleShape mCircleBase;
	sf::Color linesColor;
};

class TestCCircle :public CCircle
{
	sf::CircleShape mCircle;
};