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

void Rook::update()
{
	Piece::update();
	// ograniczenie ruchów
	if (m_position.getX() != m_prev_position.getX() && m_position.getY() != m_prev_position.getY()) {
		m_position.setX(m_prev_position.getX());
		m_position.setY(m_prev_position.getY());
	}
	int square = BoardRect::side_len;
	// brak mozliwosci 'przeskakiwania' innych bierek
	if (m_position.getX() < m_prev_position.getX()) {
		for (int i = m_position.getX() + square; i < m_prev_position.getX(); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getY() == TheGame::Instance()->black_pieces[j]->getY() && i == TheGame::Instance()->black_pieces[j]->getX()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
		for (int i = m_position.getX() + square; i < m_prev_position.getX(); i += square) {
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getY() == TheGame::Instance()->white_pieces[j]->getY() && i == TheGame::Instance()->white_pieces[j]->getX()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else {
		for (int i = m_position.getX() - square; i > m_prev_position.getX(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getY() == TheGame::Instance()->black_pieces[j]->getY() && i == TheGame::Instance()->black_pieces[j]->getX()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
		for (int i = m_position.getX() - square; i > m_prev_position.getX(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getY() == TheGame::Instance()->white_pieces[j]->getY() && i == TheGame::Instance()->white_pieces[j]->getX()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	if (m_position.getY() < m_prev_position.getY()) {
		for (int i = m_position.getY() + square; i < m_prev_position.getY(); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
		for (int i = m_position.getY() + square; i < m_prev_position.getY(); i += square) {
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else {
		for (int i = m_position.getY() - square; i > m_prev_position.getY(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
		for (int i = m_position.getY() - square; i > m_prev_position.getY(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	//szachowanie
	if (m_color == 0) {
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->black_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->black_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->black_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->black_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->black_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->black_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
	}
	else {
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->white_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->white_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->white_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->white_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->white_pieces[j]->getY()) {
					if (j == 0) {
						TheGame::Instance()->white_pieces[0]->checked = 1;
						breaking = 1;
						break;
					}
					else {
						breaking = 1;
						break;
					}
				}
			}
			if (breaking == 1) break;
		}
	}
}
