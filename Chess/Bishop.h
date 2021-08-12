#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
	Bishop(const LoaderParams* params);

	void update();
};
