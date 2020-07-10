#include "pch.h"
#include "TestingClasses.h"


/*-----------Testing Canvas Class-----------*/
TestCCanvas canvas;
CShape* newShape = nullptr;

TEST(Adding_Triangles_to_Canvas, AddFiveTriangles) 
{
	for (int i = 0; i < 5; i++)
	{
		newShape = new CTriangle(sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50));
		canvas.allShapes.push_back(newShape);
	}
	EXPECT_EQ(canvas.allShapes.size(), 5);
}

TEST(Adding_Squares_to_Canvas, AddFiveSquare )
{
	for (int i = 0; i < 5; i++)
	{
		newShape = new CSquare(sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50));
		canvas.allShapes.push_back(newShape);
	}
	EXPECT_EQ(canvas.allShapes.size(), 10);
}

TEST(Adding_Circles_to_Canvas, AddFiveCircles) 
{

	for (int i = 0; i < 5; i++)
	{
		newShape = new CCircle(sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50));
		canvas.allShapes.push_back(newShape);
	}
	EXPECT_EQ(canvas.allShapes.size(), 15);
}

TEST(Adding_FlyEyes_to_Canvas, AddFiveFlyEyes)
{
	for (int i = 0; i < 5; i++)
	{
		newShape = new CFlyEye(sf::Vector2f(rand() % 500 + 50, rand() % 500 + 50), rand() % 30 + 10);

		canvas.allShapes.push_back(newShape);
	}
	EXPECT_EQ(canvas.allShapes.size(), 20);
}

TEST(Adding_Shapes_For_Rotation, RotateShapes)
{
	for (auto& shape : canvas.allShapes)
	{
		CShape* newShape = nullptr;
		newShape = new CRotateShape(shape, canvas.rotateAngle);
		canvas.rotatedShapes.push_back(newShape);
	}
	EXPECT_EQ(canvas.allShapes.size(), canvas.rotatedShapes.size());
}

TEST(Drawing_All_Shapes, RenderWindow)
{
	for (auto& shape : canvas.allShapes)
	{
		EXPECT_NO_THROW(shape->Draw(canvas.mWindow));
	}
}

/*-----------Testing Fly Eye Class-----------*/
TEST(Point_Quantity_Check, FlyEyeClass)
{
	for (int i = 10; i < 50; i++)
	{
		int val = TestCFlyEye::CheckValidPointsQtt(i);
		EXPECT_NE(0, val);
	}
}