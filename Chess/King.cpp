#include "King.h"
#include "PieceTexture.h"
#include "InputHandler.h"
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
//	handleInput();
	Piece::update();
}

/*int x = -1, y = -1, mx = -1, my = -1; //wspó³rzêdne obiektu i myszki przed wciœniêciem lewego przycisku
void King::handleInput()
{
	int square = BoardRect::side_len;
	Vector2D *vec = TheInputHandler::Instance()->getMousePosition(); 
	if (!TheInputHandler::Instance()->getMouseButtonLeft()) { 
		x = m_position.getX();
		y = m_position.getY();
		mx = vec->getX();
		my = vec->getY();
	}
	if (TheInputHandler::Instance()->getMouseButtonLeft() && mx>x&& mx <x+square && my >y && my < y + square) {
//		m_position = *vec;
		for (int i = 0; i < 8; i++) {
				if (vec->getX() > i * square && vec->getX() < (i + 1) * square) m_position.setX(i * square);
				if (vec->getY() > i * square && vec->getY() < (i + 1) * square) m_position.setY(i * square);
			}

	}

}*/

