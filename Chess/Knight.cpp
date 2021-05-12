#include "Knight.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"

Knight::Knight(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wn_texture;
	else m_texture = PieceTexture::bn_texture;
}

void Knight::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void Knight::update()
{
	//	handleInput();
	Piece::update();
}
