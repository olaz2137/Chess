#pragma once
#include "Piece.h"

class King : public Piece {
public:
	
	King(const LoaderParams* params);

	void update();
};
