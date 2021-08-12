#include "King.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"
#include <iostream>

King::King(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wk_texture;
	else m_texture = PieceTexture::bk_texture;
}

void King::update()
{
	Piece::update();
	int square = BoardRect::side_len;
	// ograncizenie ruchów króla u¿ywaj¹c wektorów poprzedniej i aktualnej pozycji
	if (abs((m_position-m_prev_position).getX()) > square || abs((m_position - m_prev_position).getY()) > square) {
		m_position.setX(m_prev_position.getX());
		m_position.setY(m_prev_position.getY());
	}
	// ograniczenie ruchów w stosunku do drugiego króla
	if (m_color == 0) {
		if (abs(m_position.getX() - TheGame::Instance()->black_pieces[0]->getX()) < 2*square && abs(m_position.getY() - TheGame::Instance()->black_pieces[0]->getY()) < 2 * square) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
	}
	else {
		if (abs(m_position.getX() - TheGame::Instance()->white_pieces[0]->getX()) < 2 * square && abs(m_position.getY() - TheGame::Instance()->white_pieces[0]->getY()) < 2 * square) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
	}
}
