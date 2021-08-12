#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	Knight(const LoaderParams* params);

	void update();
};
