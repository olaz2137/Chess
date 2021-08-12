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

void Knight::update()
{
	//	handleInput();
	Piece::update();
	int square = BoardRect::side_len;
	// ograniczenie ruchu
	if ((abs((m_position-m_prev_position).getX()) != 2 * square || abs((m_position - m_prev_position).getY()) != square) && (abs((m_position - m_prev_position).getX()) != square || abs((m_position - m_prev_position).getY()) != 2 * square)) {
		m_position.setX(m_prev_position.getX());
		m_position.setY(m_prev_position.getY());
	}
	// szachowanie
	if (m_color == 0 && abs(TheGame::Instance()->black_pieces[0]->getX() - getX()) == square && abs(TheGame::Instance()->black_pieces[0]->getY() - getY()) == 2*square || abs(TheGame::Instance()->black_pieces[0]->getX() - getX()) == 2*square && abs(TheGame::Instance()->black_pieces[0]->getY() - getY()) == square)
		TheGame::Instance()->black_pieces[0]->checked = 1;
	else if (m_color == 1 && abs(TheGame::Instance()->white_pieces[0]->getX() - getX()) == square && abs(TheGame::Instance()->white_pieces[0]->getY() - getY()) == 2 * square || abs(TheGame::Instance()->white_pieces[0]->getX() - getX()) == 2 * square && abs(TheGame::Instance()->white_pieces[0]->getY() - getY()) == square)
		TheGame::Instance()->white_pieces[0]->checked = 1;
}
