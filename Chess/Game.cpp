#include "Game.h"
#include <iostream>
#include "PieceTexture.h"
#include "King.h"
#include "InputHandler.h"
#include "BoardRect.h"

Game* Game::s_pInstance = 0;
SDL_Renderer* Game::renderer = nullptr;
Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Game::init(const std::string& window_title, int width, int height) {
	m_window_title = window_title;
	m_width = width;
	m_height = height;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Could not initalize SDL.\n ";
		return 0;
	}

	window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);


	// Sprawdzenie czy okno zosta³o utworzone
	if (window == nullptr) {
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return 0;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	PieceTexture::loadImages();
	black_king = new King(new LoaderParams(1, 0, 0));
	white_king = new King(new LoaderParams(0, 400, 80));
}

void Game::render()
{

	int square = BoardRect::side_len;
	//tworzenie gui szachownicy
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SDL_Rect rect = { i * square, j * square,  square, square };
			if ((i+j) % 2 == 0) SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			else SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}

	black_king->draw(renderer);
	white_king->draw(renderer);
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {

	TheInputHandler::Instance()->update();
}

void Game::update()
{
	black_king->update();
	white_king->update();
}
