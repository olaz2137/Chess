#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(const LoaderParams* params);

	void update();
};
