#include "CIsometricShape.h"

CRotateShape::CRotateShape(CShape* shape, float angle)
{
	mType = shapeType::ISOMETRIC;
	mPoints = shape->GetPoints();
	rotate(angle);
	SavePoints();
	PointShape();
	mShape.setPosition(shape->GetPosition().x + mShape.getScale().x / 2, shape->GetPosition().y + mShape.getScale().y / 2);
	mShape.setOutlineColor(shape->GetOutlineColor());
	mShape.setFillColor(shape->GetFillColor());
}

void CRotateShape::ConsolePrintPoints(int index)
{
	for (int i = 0; i < mPoints.size(); i++)
	{
		printf("%d/t[%d]/tx: %d/ty: %d/n", index, i, mPoints[i].x, mPoints[i].y);
	}
}

void CRotateShape::SavePoints()
{
	for (int i = 0; i < mShape.getPointCount(); i++)
	{
		mPoints.push_back(mShape.getPoint(i));
	}
}

void CRotateShape::rotate(float angle)
{
	for (auto& point : mPoints)
	{
		point.x = ((cosf(angle) * point.x) - (sinf(angle) * point.y));
		point.y = ((sinf(angle) * point.x) + (cos(angle) * point.y));
	}
}

void CRotateShape::PointShape()
{
	mShape.setPointCount(mPoints.size());
	for (int i = 0; i < mPoints.size(); i++)
	{
		mShape.setPoint(i, mPoints[i]);
	}
}





