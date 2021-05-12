#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(const LoaderParams* params);

	void draw(SDL_Renderer* renderer);
	void update();
	//	void clean();
};