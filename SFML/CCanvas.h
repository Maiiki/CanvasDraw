#pragma once
#include "CCircle.h"
#include "CTriangle.h"
#include "CSquare.h"
#include "CFlyEye.h"
#include "CIsometricShape.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class CCanvas
{
public:
	static CCanvas& instance();
	void Run();

private:
	CCanvas();
	void ProcessEvents();
	void HandleInput(sf::Keyboard::Key key, bool isPressed);
	void HandleInput(sf::Mouse::Button btn, int x, int y);
	void Update(sf::Time deltaTime);
	void Render();
	void ConsolePrintShapesPoints();
	

private:
	sf::RenderWindow mWindow;
	sf::Time mTimePerFrame;
	bool mbCircle, mbTriangle, mbSquare, mbFlyEye, mbIsometric, mbDrawing, mbErase, mbUndo;
	std::vector<CShape*> allShapes;
	std::vector<CShape*>rotatedShapes;
	sf::Vector2i drawPosition;
};

