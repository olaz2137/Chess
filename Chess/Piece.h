#pragma once
#include <string>
#include "SDL.h"
#include "LoaderParams.h"
#include "Vector2D.h"

/// <summary>
/// Klasa podstawowa wszystkich bierek
/// </summary>
class Piece {
public:

	Piece(const LoaderParams* params);

	Vector2D m_prev_position;
	Vector2D m_position;

	void draw(SDL_Renderer* renderer);
	virtual void update() = 0;

	int getX() { return x; }
	int getY() { return y; }

	void setX(int cx) { m_position.setX(cx); }
	void setY(int cy) { m_position.setY(cy); }

	bool moved = 0;
	bool checked = 0;

protected:
	
	bool m_color; // 0 dla bia³ego, 1 dla czarnego
	SDL_Texture* m_texture;

	int m_x = -1, m_y = -1, x = -2, y = -2; //wspó³rzêdne bierki i myszki przed wciœniêciem lewego przycisku
};
