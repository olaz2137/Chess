#include "Bishop.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"

Bishop::Bishop(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wb_texture;
	else m_texture = PieceTexture::bb_texture;
}

void Bishop::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void Bishop::update()
{
	//	handleInput();
	Piece::update();
}
