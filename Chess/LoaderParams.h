#pragma once
#include "SDL.h"

class LoaderParams {
public:
	LoaderParams(bool color, int x, int y)
		:m_color(color),m_x(x), m_y(y) {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	SDL_Texture* getTexture() const { return m_texture; }
	bool getColor() const { return m_color;  }

private:
	bool m_color; // 0 dla bia³ego, 1 dla czarnego
	SDL_Texture* m_texture;

	int m_x;
	int m_y;

};
