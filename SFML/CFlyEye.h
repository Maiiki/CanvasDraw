#pragma once
#include "CShape.h"
#include <vector>

class CFlyEye :
    public CShape
{
public:
    CFlyEye(sf::Vector2f position, int points);
    CFlyEye(sf::Vector2f position, int points, float radius);
    CFlyEye(sf::Vector2f position, int points, float radius, sf::Color linecolor);

    inline void SetPosition(float x, float y)override { mCircleBase.setPosition(x, y); };
    inline void SetSize(float x, float y)override { mCircleBase.setRadius(x / 2); };
    inline void SetFillColor(sf::Color color)override { mCircleBase.setFillColor(color); };
    inline void SetLinesColor(sf::Color color) { linesColor = color; };

    inline sf::Color GetFillColor() { return mCircleBase.getFillColor(); };
    inline sf::Vector2f GetPosition() { return mCircleBase.getPosition(); };
    inline sf::Color GetOutlineColor() { return mCircleBase.getOutlineColor(); };

    void Draw(sf::RenderWindow& window)override;
    inline std::vector<sf::Vector2f> GetPoints()override { return mPoints; };

private:
    void ConsolePrintPoints(int index)override;
    void SavePoints()override;

private:
    sf::CircleShape mCircleBase;
    sf::Color linesColor;
};

