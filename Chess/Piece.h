#pragma once
#include <string>
#include "SDL.h"
#include "LoaderParams.h"
#include "PieceBase.h"
#include "Vector2D.h"

/// <summary>
/// 
/// </summary>
class Piece : public PieceBase{
public:

	Piece(const LoaderParams* params);

	virtual void draw(SDL_Renderer* renderer);
	virtual void update(); 
//	void promote();
//	virtual void clean() = 0;
//	virtual void handleInput();


	

protected:
	
	bool m_color; // 0 dla bia³ego, 1 dla czarnego
	SDL_Texture* m_texture;

	Vector2D m_position;
	Vector2D m_velocity;

	int x = -1, y = -1, mx = -2, my = -2; //wspó³rzêdne obiektu i myszki przed wciœniêciem lewego przycisku
};
