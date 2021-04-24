#include "Queen.h"
#include "PieceTexture.h"
#include "InputHandler.h"
#include "Game.h"
#include "BoardRect.h"

Queen::Queen(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wq_texture;
	else m_texture = PieceTexture::bq_texture;
}

void Queen::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void Queen::update()
{
	//	handleInput();
	Piece::update();
}
