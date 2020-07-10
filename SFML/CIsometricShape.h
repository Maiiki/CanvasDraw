#pragma once
#include "CShape.h"
#include <vector>

class CRotateShape :
    public CShape
{
public:
    /**
     * Constructor. Receives a shape and the angle it will be rotated.
     * 
     * \param shape Shape to be rotated, can be a CCircle or CSquare
     * \param angle Degrees to rotate the shape. The value is in decimals, e.g. 60° = .60f
     */
    CRotateShape(CShape* shape, float angle);
    inline void SetPosition(float x, float y)override { mShape.setPosition(x, y); };
    inline void SetSize(float x, float y)override { mShape.setScale(sf::Vector2f(x, y)); };
    inline void SetFillColor(sf::Color color)override { mShape.setFillColor(color); };

    inline sf::Color GetFillColor() { return mShape.getFillColor(); };
    inline sf::Color GetOutlineColor() { return mShape.getOutlineColor(); };
    inline sf::Vector2f GetPosition() { return mShape.getPosition(); };


    inline void Draw(sf::RenderWindow& window) override { window.draw(mShape); };
    inline std::vector<sf::Vector2f> GetPoints() { return mPoints; };

protected:
    void ConsolePrintPoints(int index)override;
    void SavePoints();
    /**
     * Rotates each point of the shape.
     * 
     * \param angle Degrees to rotate the shape
     */
    void rotate(float angle);
    /**
     * Sets the points for the shape.
     * 
     */
    void PointShape();

protected:
    //!Convex shape that will serve as the rotated shape
    sf::ConvexShape mShape;
};

