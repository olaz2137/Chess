#include "Game.h"
#include <iostream>
#include "PieceTexture.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "InputHandler.h"
#include "BoardRect.h"

Game* Game::s_pInstance = 0;
SDL_Renderer* Game::renderer = nullptr;
Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	for (std::vector<Piece*>::size_type i = 0; i != white_pieces.size(); i++)
	{
		delete white_pieces[i];
	}

	for (std::vector<Piece*>::size_type i = 0; i != black_pieces.size(); i++)
	{
		delete black_pieces[i];
	}
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
	int square = BoardRect::side_len;
	// inicjowanie pozycji pocz¹tkowych bierek
	black_king = new King(new LoaderParams(1, 4* square, 0));
	black_queen = new Queen(new LoaderParams(1, 3 * square, 0));
	black_rook = new Rook(new LoaderParams(1, 0, 0));
	black_rook2 = new Rook(new LoaderParams(1, 7 * square,0));
	black_bishop = new Bishop(new LoaderParams(1, 2*square, 0));
	black_bishop2 = new Bishop(new LoaderParams(1, 5* square, 0));
	black_knight = new Knight(new LoaderParams(1, square, 0));
	black_knight2 = new Knight(new LoaderParams(1, 6 * square, 0));
	black_pawn = new Pawn(new LoaderParams(1, 0, square));
	black_pawn2 = new Pawn(new LoaderParams(1, square , square));
	black_pawn3 = new Pawn(new LoaderParams(1, square * 2, square));
	black_pawn4 = new Pawn(new LoaderParams(1, square * 3, square));
	black_pawn5 = new Pawn(new LoaderParams(1, square * 4, square));
	black_pawn6 = new Pawn(new LoaderParams(1, square * 5, square));
	black_pawn7 = new Pawn(new LoaderParams(1, square * 6, square));
	black_pawn8 = new Pawn(new LoaderParams(1, square * 7, square));

	white_king = new King(new LoaderParams(0, 4 * square, 7 * square));
	white_queen = new Queen(new LoaderParams(0, 3 * square, 7 * square));
	white_rook = new Rook(new LoaderParams(0, 0, 7 * square));
	white_rook2 = new Rook(new LoaderParams(0, 7 * square, 7 * square));
	white_bishop = new Bishop(new LoaderParams(0, 2*square, 7 * square));
	white_bishop2 = new Bishop(new LoaderParams(0, 5 * square, 7 * square));
	white_knight = new Knight(new LoaderParams(0, square, 7 * square));
	white_knight2 = new Knight(new LoaderParams(0, 6 * square, 7 * square));
	white_pawn = new Pawn(new LoaderParams(0, 0, 6 * square));
	white_pawn2 = new Pawn(new LoaderParams(0, square, 6 * square ));
	white_pawn3 = new Pawn(new LoaderParams(0, square*2, 6 * square));
	white_pawn4 = new Pawn(new LoaderParams(0, square * 3, 6 * square));
	white_pawn5 = new Pawn(new LoaderParams(0, square * 4, 6 * square));
	white_pawn6 = new Pawn(new LoaderParams(0, square * 5, 6 * square));
	white_pawn7 = new Pawn(new LoaderParams(0, square * 6, 6 * square));
	white_pawn8 = new Pawn(new LoaderParams(0, square * 7, 6 * square));

	white_pieces.push_back(white_king);
	white_pieces.push_back(white_queen);
	white_pieces.push_back(white_rook);
	white_pieces.push_back(white_rook2);
	white_pieces.push_back(white_bishop);
	white_pieces.push_back(white_bishop2);
	white_pieces.push_back(white_knight);
	white_pieces.push_back(white_knight2);
	white_pieces.push_back(white_pawn);
	white_pieces.push_back(white_pawn2);
	white_pieces.push_back(white_pawn3);
	white_pieces.push_back(white_pawn4);
	white_pieces.push_back(white_pawn5);
	white_pieces.push_back(white_pawn6);
	white_pieces.push_back(white_pawn7);
	white_pieces.push_back(white_pawn8);

	black_pieces.push_back(black_king);
	black_pieces.push_back(black_queen);
	black_pieces.push_back(black_rook);
	black_pieces.push_back(black_rook2);
	black_pieces.push_back(black_bishop);
	black_pieces.push_back(black_bishop2);
	black_pieces.push_back(black_knight);
	black_pieces.push_back(black_knight2);
	black_pieces.push_back(black_pawn);
	black_pieces.push_back(black_pawn2);
	black_pieces.push_back(black_pawn3);
	black_pieces.push_back(black_pawn4);
	black_pieces.push_back(black_pawn5);
	black_pieces.push_back(black_pawn6);
	black_pieces.push_back(black_pawn7);
	black_pieces.push_back(black_pawn8);
}

void Game::render()
{

	int square = BoardRect::side_len;
	//tworzenie gui szachownicy
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SDL_Rect rect = { i * square, j * square,  square, square };
			if ((i+j) % 2 == 0) SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
			else SDL_SetRenderDrawColor(renderer, 157, 98, 146, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}

	for (std::vector<Piece*>::size_type i = 0; i != white_pieces.size(); i++)
	{
		white_pieces[i]->draw(renderer);
	}

	for (std::vector<Piece*>::size_type i = 0; i != black_pieces.size(); i++)
	{
		black_pieces[i]->draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {

	TheInputHandler::Instance()->update();
}

void Game::update()
{
	for (std::vector<Piece*>::size_type i = 0; i != white_pieces.size(); i++)
	{
		white_pieces[i]->update();
	}

	for (std::vector<Piece*>::size_type i = 0; i != black_pieces.size(); i++)
	{
		black_pieces[i]->update();
	}
}
