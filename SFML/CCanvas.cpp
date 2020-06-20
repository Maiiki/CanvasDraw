#include "CCanvas.h"

/*-Instancia*/
//////////////////////////////////////////////////////
CCanvas& CCanvas::instance()
{
	static CCanvas* instance = new CCanvas();
	return *instance;
}

/*-GameLoop-*/
//////////////////////////////////////////////////////
void CCanvas::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		ProcessEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > mTimePerFrame)
		{
			timeSinceLastUpdate -= mTimePerFrame;
			ProcessEvents();
			Update(mTimePerFrame);
		}
		Render();
	}
}
//////////////////////////////////////////////////////

/*-Constructor*/
//////////////////////////////////////////////////////
CCanvas::CCanvas()
	:mWindow(sf::VideoMode(1000, 1000), "Basic Shapes"),
	mbCircle(false), mbTriangle(false), mbSquare(false), mbFlyEye(false), mbIsometric(false), mbDrawing(false), mbErase(false), mbUndo(false),
	mTimePerFrame(sf::seconds(1.f / 60.f))
{
	srand(time(NULL));
}
//////////////////////////////////////////////////////

/*-Eventos*/
//////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////

/*-Input*/
//////////////////////////////////////////////////////
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
	if(btn == sf::Mouse::Left)
	{
		if (mbCircle || mbTriangle || mbSquare || mbFlyEye)
		{
			mbDrawing = true;
			drawPosition = sf::Vector2i(x, y);
		}
	}
}

//////////////////////////////////////////////////////
/*-Update*/
//////////////////////////////////////////////////////
void CCanvas::Update(sf::Time deltaTime)
{
	// Update Shapes
	if(mbDrawing)
	{
		CShape* newShape = nullptr;
		if(mbTriangle)
		{
			newShape = new CTriangle(sf::Vector2f(drawPosition.x, drawPosition.y), //mouse position
				(float)(rand()%500+50), //random size
				sf::Color(rand()%255, rand() % 255, rand() % 255, rand() % 255+100)); //random color
			allShapes.push_back(newShape);
		}
		if(mbSquare)
		{
			newShape = new CSquare(sf::Vector2f(drawPosition.x, drawPosition.y),//mouse position
				sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50), //radius
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //random color
			allShapes.push_back(newShape);
		}
		if(mbCircle)
		{
			newShape = new CCircle(sf::Vector2f(drawPosition.x, drawPosition.y),//mouse position
				(float)(rand() % 500 + 50), //radius
				sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255 + 100)); //random color
			allShapes.push_back(newShape);
		}
		if (mbFlyEye)
		{
			newShape = new CFlyEye(sf::Vector2f(drawPosition.x, drawPosition.y), //mouse position
				rand() % 20 + 10, //point number
				(float)(rand() % 500 + 50), //radius
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
			newShape = new CRotateShape(shape, .60f);
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
//////////////////////////////////////////////////////

/*-Render*/
//////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////




