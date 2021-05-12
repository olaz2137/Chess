#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(const LoaderParams* params);

	void draw(SDL_Renderer* renderer);
	void update();
	//	void clean();
};
