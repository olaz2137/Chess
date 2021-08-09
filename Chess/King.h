#pragma once
#include "Piece.h"

class King : public Piece {
public:
	
	King(const LoaderParams* params);

	void draw(SDL_Renderer* renderer);
	void update();
	
//	void clean();

private:
//	void handleInput();
};
