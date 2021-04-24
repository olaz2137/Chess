#pragma once
#include <string>
#include "SDL.h"
#include "LoaderParams.h"

/// <summary>
/// 
/// </summary>
class PieceBase {
public:

	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void update() = 0;
	//	void promote();
	//	virtual void clean() = 0;



protected:

	PieceBase(const LoaderParams* params) {}
	virtual ~PieceBase() {}
};