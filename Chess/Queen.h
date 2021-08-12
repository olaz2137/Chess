#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(const LoaderParams* params);

	void update();
};
