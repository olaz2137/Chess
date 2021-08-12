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

void Queen::update()
{
	Piece::update();
	int square = BoardRect::side_len;
	// ograniczenie ruchow
	if (abs((m_position - m_prev_position).getX()) != abs((m_position - m_prev_position).getY()) && m_position.getX() != m_prev_position.getX() && m_position.getY() != m_prev_position.getY()) {
		m_position.setX(m_prev_position.getX());
		m_position.setY(m_prev_position.getY());
	}
	// ograniczenie 'przeskakiwania'
	if (m_position.getX() > m_prev_position.getX() && m_position.getY() > m_prev_position.getY()) {
		for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_prev_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_prev_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else if (m_position.getX() < m_prev_position.getX() && m_position.getY() > m_prev_position.getY()) {
		for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_prev_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_prev_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else if (m_position.getX() < m_prev_position.getX() && m_position.getY() < m_prev_position.getY()) {
		for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_prev_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_prev_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else if (m_position.getX() > m_prev_position.getX() && m_position.getY() < m_prev_position.getY()) {
		for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_prev_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_prev_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	else if (m_position.getX() == m_prev_position.getX()) {
		if (m_position.getY() > m_prev_position.getY()) {
			for (int i = square; i < abs((m_position - m_prev_position).getY()); i += square) {
				for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
					if (m_prev_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
				for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
					if (m_prev_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
			}
		}
		else if (m_position.getY() < m_prev_position.getY()) {
			for (int i = square; i < abs((m_position - m_prev_position).getY()); i += square) {
				for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
					if (m_prev_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
				for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
					if (m_prev_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && m_prev_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
			}
		}
	}
	else if (m_position.getY() == m_prev_position.getY()) {
		if (m_position.getX() > m_prev_position.getX())
			for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
				for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
					if (m_prev_position.getY() == TheGame::Instance()->black_pieces[j]->getY() && m_prev_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
				for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
					if (m_prev_position.getY() == TheGame::Instance()->white_pieces[j]->getY() && m_prev_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
			}
		else if (m_position.getX() < m_prev_position.getX())
			for (int i = square; i < abs((m_position - m_prev_position).getX()); i += square) {
				for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
					if (m_prev_position.getY() == TheGame::Instance()->black_pieces[j]->getY() && m_prev_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
				for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
					if (m_prev_position.getY() == TheGame::Instance()->white_pieces[j]->getY() && m_prev_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX()) {
						m_position.setX(m_prev_position.getX());
						m_position.setY(m_prev_position.getY());
					}
				}
			}
	}
	//szachowanie
	//jak dla wiezy
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
	//jak dla gonca
	if (m_color == 0) {
		for (int i = square; i < 8 * square; i += square) {
			bool breaking = 0;
			for (int j = 0; j < TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
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
				if (m_position.getX() + i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
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
				if (m_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->black_pieces[j]->getY()) {
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
				if (m_position.getX() - i == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->black_pieces[j]->getY()) {
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
				if (m_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
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
				if (m_position.getX() + i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
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
				if (m_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() - i == TheGame::Instance()->white_pieces[j]->getY()) {
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
				if (m_position.getX() - i == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() + i == TheGame::Instance()->white_pieces[j]->getY()) {
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
