#include "Pawn.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"

Pawn::Pawn(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wp_texture;
	else m_texture = PieceTexture::bp_texture;
}

void Pawn::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void Pawn::update()
{
	//	handleInput();
	Piece::update();
}
