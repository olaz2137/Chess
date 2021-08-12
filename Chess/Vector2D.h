#pragma once
#include <math.h>

/// <summary>
/// Wspolrzedne x i y dla bierek
/// </summary>
class Vector2D {
public:

    Vector2D(int x, int y) : m_x(x), m_y(y) {}

    int getX() { return m_x; }
    int getY() { return m_y; }

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }

    Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
    }

private:

    int m_x;
    int m_y;
};
