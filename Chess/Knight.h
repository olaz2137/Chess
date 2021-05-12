#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	Knight(const LoaderParams* params);

	void draw(SDL_Renderer* renderer);
	void update();
	//	void clean();
};