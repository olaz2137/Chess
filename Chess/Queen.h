#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(const LoaderParams* params);

	void draw(SDL_Renderer* renderer);
	void update();
	//	void clean();
};