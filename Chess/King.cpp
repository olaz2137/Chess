#include "King.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"

King::King(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wk_texture;
	else m_texture = PieceTexture::bk_texture;
}

void King::draw(SDL_Renderer* renderer)
{
	Piece::draw(renderer);
}

void King::update()
{
	Piece::update();
	// ograncizenie ruchów króla u¿ywaj¹c wektorów poprzedniej i aktualnej pozycji
	int square = BoardRect::side_len;
	if (m_prev_position.getX()!= -1 && m_prev_position.getY() != -1  && (abs((m_position-m_prev_position).getX())>square || abs((m_position - m_prev_position).getY()) > square) ) {
		m_position.setX(m_prev_position.getX());
		m_position.setY(m_prev_position.getY());

		m_prev_position.setX(-1);
		m_prev_position.setY(-1);
	}
}



