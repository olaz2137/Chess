#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler() : m_mousePosition(new Vector2D(0, 0)) {}

void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			TheGame::Instance()->quit();
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
			if (event.button.button == SDL_BUTTON_LEFT)
				m_mouseButtonLeft = true;
		if (event.type == SDL_MOUSEBUTTONUP)
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonLeft = false;
			}
		if (event.type == SDL_MOUSEMOTION) {

			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}

	}
}
