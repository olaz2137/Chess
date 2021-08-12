#include "Piece.h"
#include "SDL_image.h"
#include "Game.h"
#include "InputHandler.h"
#include "BoardRect.h"


Piece::Piece(const LoaderParams* params):
	m_position(params->getX(), params->getY()), m_prev_position(params->getX(), params->getY()), m_color(params->getColor()) {}

void Piece::draw(SDL_Renderer* renderer)
{
	SDL_Rect sourceRect = { 0,0,80,80 };
	SDL_Rect destinationRect = { m_position.getX(),m_position.getY(),80,80 };
	SDL_RenderCopy(renderer, m_texture, &sourceRect, &destinationRect);
}


void Piece::update() { 
	int square = BoardRect::side_len;
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (!TheInputHandler::Instance()->getMouseButtonLeft()) {
		x = m_position.getX();
		y = m_position.getY();
		m_x = vec->getX();
		m_y = vec->getY();
	}
	// ograniczenie ruchów do pól szachownicy
	if (TheInputHandler::Instance()->getMouseButtonLeft() && m_x > x && m_x <x + square && m_y >y && m_y < y + square) {
		m_prev_position.setX(x);
		m_prev_position.setY(y);
		for (int i = 0; i < 8; i++) {
			if (vec->getX() > i * square && vec->getX() < (i + 1) * square) m_position.setX(i * square);
			if (vec->getY() > i * square && vec->getY() < (i + 1) * square) m_position.setY(i * square);
		}

	}
}


