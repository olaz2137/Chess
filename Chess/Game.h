#pragma once
#include <string>
#include "SDL.h"
#include "King.h"
#include <vector>

/// <summary>
/// 
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

	bool init(const std::string& window_title, int width, int height);

	void handleEvents(); //Obs³uga zdarzeñ
	void update();
	void render(); 
	void quit() { closed = true; }
	bool isClosed() { return closed; }
	bool isWhiteMove() { return white_move; }
	bool white_move = true;

	static SDL_Renderer* renderer;

	

private:
	Game(){}
	static Game* s_pInstance;

	std::string m_window_title;
	int m_width ;
	int m_height ;
	bool closed = false;


	SDL_Window* window = nullptr;

	std::vector <Piece*> white_pieces;
	std::vector <Piece*> black_pieces;
	
	Piece* black_king;
	Piece* white_king;
};
typedef Game TheGame;
