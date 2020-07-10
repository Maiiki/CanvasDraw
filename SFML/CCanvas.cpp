#include "CCanvas.h"

CCanvas& CCanvas::instance()
{
	static CCanvas* instance = new CCanvas();
	return *instance;
}

void CCanvas::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > mFramesPerSeconds)
		{
			timeSinceLastUpdate -= mFramesPerSeconds;
			ProcessEvents();
			Update(mFramesPerSeconds);
		}
		Render();
	}
}


CCanvas::CCanvas()
	:mWindow(sf::VideoMode(1000, 1000), "Basic Shapes"),
	mbCircle(false), mbTriangle(false), mbSquare(false), mbFlyEye(false), mbIsometric(false), mbDrawing(false), mbErase(false), mbUndo(false),
	mFramesPerSeconds(sf::seconds(1.f / 60.f)), rotateAngle(.60f)
{
	srand(time(NULL));
}
/**
 * Events proccessed:
 *	- keyboard events
 *		-# key press event
 *		-# key release event
 *	- mouse events
 *		-# mouse click event
 *	- window events
 *		-# window close event
 */
void CCanvas::ProcessEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			HandleInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandleInput(event.key.code, false);
			break;
		case sf::Event::MouseButtonPressed:
			HandleInput(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}
/**
 * Keyboard inputs handled:
 *	- C	|	Draw a circle
 *	- S	|	Draw a rectangle
 *	- T	|	Draw a Triangle
 *	- F	|	Draw a Fly Eye
 *	- I	|	Alternate between isometric an normal view
 *	- X	|	Delete all shapes
 *	- Z	|	Delete the last shape
 */
void CCanvas::HandleInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::C) { mbCircle = isPressed; }
	else if (key == sf::Keyboard::S) { mbSquare = isPressed; }
	else if (key == sf::Keyboard::T) { mbTriangle = isPressed; }
	else if (key == sf::Keyboard::F) { mbFlyEye = isPressed; }
	else if (key == sf::Keyboard::I) { mbIsometric = isPressed; }
	else if (key == sf::Keyboard::X) { mbErase = isPressed; }
	else if (key == sf::Keyboard::Z) { mbUndo = isPressed; }
	else if (key == sf::Keyboard::Escape) { mWindow.close(); }
}

void CCanvas::HandleInput(sf::Mouse::Button btn, int x, int y)
{
	if (btn == sf::Mouse::Left)
	{
		if (mbCircle || mbTriangle || mbSquare || mbFlyEye)
		{
			mbDrawing = true;
			drawPosition = sf::Vector2i(x, y);
		}
	}
}

void CCanvas::Update(sf::Time deltaTime)
{
	//Updates Shapes
	if (mbDrawing)
	{
		CShape* newShape = nullptr;
		if (mbTriangle)
		{
			newShape = new CTriangle(sf::Vector2f(drawPosition.x, drawPosition.y), //Draws in the clicked position.
				(float)(rand() % 500 + 50), //Sets random radius between 50 and 500.
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //Sets a random color.
			allShapes.push_back(newShape);
		}
		if (mbSquare)
		{
			newShape = new CSquare(sf::Vector2f(drawPosition.x, drawPosition.y),//Draws in the clicked position.
				sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50), //Sets random height and width (different) between 50 and 500.
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //Sets a random color.
			allShapes.push_back(newShape);
		}
		if (mbCircle)
		{
			newShape = new CCircle(sf::Vector2f(drawPosition.x, drawPosition.y),//Draws in the clicked position
				(float)(rand() % 500 + 50), //Sets random radius between 50 and 500.
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //Sets a random color.
			allShapes.push_back(newShape);
		}
		if (mbFlyEye)
		{
			newShape = new CFlyEye(sf::Vector2f(drawPosition.x, drawPosition.y), //Draws in the clicked position
				rand() % 20 + 10, //Sets a random point number between 10 and 20.
				(float)(rand() % 500 + 50), //Sets random radius between 50 and 500.
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //random color

			allShapes.push_back(newShape);
		}
		newShape = nullptr;
		delete(newShape);
		mbDrawing = false;
	}

	if (mbIsometric && (rotatedShapes.size() != allShapes.size()))
	{
		rotatedShapes.clear();
		for (auto& shape : allShapes)
		{
			CShape* newShape = nullptr;
			newShape = new CRotateShape(shape, rotateAngle);
			rotatedShapes.push_back(newShape);
		}
	}

	if (mbErase)
	{
		allShapes.clear();
		mbErase = false;
	}

	if (mbUndo)
	{
		if (!allShapes.empty())
		{
			allShapes.pop_back();
			mbUndo = false;
		}
	}
}

void CCanvas::Render()
{
	mWindow.clear();
	//Draw Shapes
	if (mbIsometric)
	{
		for (auto& shape : rotatedShapes)
		{
			shape->Draw(mWindow);
		}
	}
	else
	{
		for (auto& shape : allShapes)
		{
			shape->Draw(mWindow);
		}
	}
	mWindow.display();
}

void CCanvas::ConsolePrintShapesPoints()
{
	for (int i = 0; i < allShapes.size(); i++)
	{
		allShapes[i]->ConsolePrintPoints(i);
	}

	for (int i = 0; i < rotatedShapes.size(); i++)
	{
		rotatedShapes[i]->ConsolePrintPoints(i);
	}
}
