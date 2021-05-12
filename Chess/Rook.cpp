#include "Rook.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"

Rook::Rook(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wr_texture;
	else m_texture = PieceTexture::br_texture;
}

void Rook::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void Rook::update()
{
	//	handleInput();
	Piece::update();
}
