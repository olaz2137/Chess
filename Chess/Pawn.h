#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(const LoaderParams* params);

	void update();
};
