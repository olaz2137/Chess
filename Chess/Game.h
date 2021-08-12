#pragma once
#include <string>
#include "SDL.h"
#include <vector>
#include "Piece.h"
#include "BoardRect.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

/// <summary>
/// Klasa odpowiedzialna za logike i GUI gry
/// </summary>
class Game {
public:
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	~Game();

	/// <summary>
	/// Inicjalizacja GUI gry
	/// </summary>
	/// <param name="window_title"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <returns></returns>
	bool init(const std::string& window_title, int width, int height);

	void handleEvents(); //Obs³uga zdarzeñ
	/// <summary>
	/// Aktualizacja pozycji bierek
	/// </summary>
	void update();
	/// <summary>
	/// Renderowanie obrazu szachownicy i bierek
	/// </summary>
	void render(); 
	void quit() { closed = true; }
	bool isClosed() { return closed; }
	bool isWhiteMove() { return white_move; }
	bool white_move = true;

	static SDL_Renderer* renderer;

	/// <summary>
	/// vectory przechowywujace bierki danego koloru
	/// </summary>
	std::vector <Piece*> white_pieces;
	std::vector <Piece*> black_pieces;

	Piece* black_king;
	Piece* black_queen;
	Piece* black_rook;
	Piece* black_rook2;
	Piece* black_bishop;
	Piece* black_bishop2;
	Piece* black_knight;
	Piece* black_knight2;
	Piece* black_pawn;
	Piece* black_pawn2;
	Piece* black_pawn3;
	Piece* black_pawn4;
	Piece* black_pawn5;
	Piece* black_pawn6;
	Piece* black_pawn7;
	Piece* black_pawn8;

	Piece* white_king;
	Piece* white_queen;
	Piece* white_rook;
	Piece* white_rook2;
	Piece* white_bishop;
	Piece* white_bishop2;
	Piece* white_knight;
	Piece* white_knight2;
	Piece* white_pawn;
	Piece* white_pawn2;
	Piece* white_pawn3;
	Piece* white_pawn4;
	Piece* white_pawn5;
	Piece* white_pawn6;
	Piece* white_pawn7;
	Piece* white_pawn8;

private:
	static Game* s_pInstance;

	std::string m_window_title;
	int m_width ;
	int m_height ;
	bool closed = false;

	SDL_Window* window = nullptr;

	///poprzednie pozycje bierek
	std::vector <Vector2D*> white_pos_storage;
	std::vector <Vector2D*> black_pos_storage;
};
typedef Game TheGame;
