#include "Pawn.h"
#include "Queen.h"
#include "PieceTexture.h"
#include "Game.h"
#include "BoardRect.h"
#include <iostream>

Pawn::Pawn(const LoaderParams* params)
	:Piece(params)
{
	if (m_color == 0) m_texture = PieceTexture::wp_texture;
	else m_texture = PieceTexture::bp_texture;
}

void Pawn::update()
{
	Piece::update();
	int square = BoardRect::side_len;
	// bicie przez piony
	bool white_killed = 0;
	bool black_killed = 0;
	if (m_color == 0 && (m_position - m_prev_position).getY() ==  -square && abs((m_position - m_prev_position).getX()) == square) {
		for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
			if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->black_pieces[j]->getY()) {
				black_killed = 1;
			}
		}
	}
	if (m_color == 1 && (m_position - m_prev_position).getY() == square && abs((m_position - m_prev_position).getX()) == square) {
		for (int j = 1; j != TheGame::Instance()->white_pieces.size(); j++) {
			if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && m_position.getY() == TheGame::Instance()->white_pieces[j]->getY()) {
				white_killed = 1;
			}
		}
	}
	// ograniczenie 'przeskakiwania'
	if (m_color == 0 && black_killed == 0) {
		for (int i = m_position.getY(); i < m_prev_position.getY(); i += square) {
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
	else if (m_color == 1 && white_killed == 0) {
		for (int i = m_position.getY() - square; i > m_prev_position.getY(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->black_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->black_pieces[j]->getX() && i == TheGame::Instance()->black_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
		for (int i = m_position.getY(); i > m_prev_position.getY(); i -= square) {
			for (int j = 0; j != TheGame::Instance()->white_pieces.size(); j++) {
				if (m_position.getX() == TheGame::Instance()->white_pieces[j]->getX() && i == TheGame::Instance()->white_pieces[j]->getY()) {
					m_position.setX(m_prev_position.getX());
					m_position.setY(m_prev_position.getY());
				}
			}
		}
	}
	// ograniczenie ruchów piona
	// bia³e piony
	if (m_color == 0 && black_killed == 0) {
		// koljene ruchy piona
		if (moved == 1 && ((m_position - m_prev_position).getY() > 0 || (m_position - m_prev_position).getY() < -1 * square || m_position.getX() != m_prev_position.getX())) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
		// pierwszy ruch piona
		else if (moved == 0 && ((m_position - m_prev_position).getY() > 0 || (m_position - m_prev_position).getY() < -2 * square || m_position.getX() != m_prev_position.getX())) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
	}
	// czarne piony
	else if (m_color == 1 && white_killed == 0) {
		// koljene ruchy piona
		if (moved == 1 && ((m_position - m_prev_position).getY() < 0 || (m_position - m_prev_position).getY() > square || m_position.getX() != m_prev_position.getX())) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
		// pierwszy ruch piona
		else if (moved == 0 && ((m_position - m_prev_position).getY() < 0 || (m_position - m_prev_position).getY() > 2 * square || m_position.getX() != m_prev_position.getX())) {
			m_position.setX(m_prev_position.getX());
			m_position.setY(m_prev_position.getY());
		}
	}
	// szachowanie
	if (m_color == 0 && abs(TheGame::Instance()->black_pieces[0]->getX() - getX()) == square && getY() - TheGame::Instance()->black_pieces[0]->getY() == square)
		TheGame::Instance()->black_pieces[0]->checked = 1;
	else if (m_color == 1 && abs(TheGame::Instance()->white_pieces[0]->getX() - getX()) == square && TheGame::Instance()->white_pieces[0]->getY() - getY() == square)
		TheGame::Instance()->white_pieces[0]->checked = 1;
}
