#pragma once
#include "SDL.h"

/// <summary>
/// Parametry 
/// </summary>
class LoaderParams {
public:
	LoaderParams(bool color, int x, int y)
		:m_color(color),m_x(x), m_y(y) {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	bool getColor() const { return m_color;  }

private:
	/// <summary>
	/// Kolor bierek: 0 dla bia³ego, 1 dla czarnego
	/// </summary>
	bool m_color;
	int m_x;
	int m_y;

};
