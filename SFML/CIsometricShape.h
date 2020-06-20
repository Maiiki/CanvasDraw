#pragma once
#include "CShape.h"
#include <vector>

class CRotateShape :
    public CShape
{
public:
    CRotateShape(CShape* shape, float angle);
    inline void SetPosition(float x, float y)override { mShape.setPosition(x, y); };
    inline void SetSize(float x, float y)override { mShape.setScale(sf::Vector2f(x, y)); };
    inline void SetFillColor(sf::Color color)override { mShape.setFillColor(color); };

    inline sf::Color GetFillColor() { return mShape.getFillColor(); };
    inline sf::Color GetOutlineColor() { return mShape.getOutlineColor(); };
    inline sf::Vector2f GetPosition() { return mShape.getPosition(); };


    inline void Draw(sf::RenderWindow& window) override { window.draw(mShape); };
    inline std::vector<sf::Vector2f> GetPoints() { return mPoints; };

private:
    void ConsolePrintPoints(int index)override;
    void SavePoints();
    void rotate(float angle);
    void PointShape();

private:
    sf::ConvexShape mShape;
};

