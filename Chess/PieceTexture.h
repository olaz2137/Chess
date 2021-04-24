#pragma once
#include "SDL.h"

class PieceTexture {
public:

	~PieceTexture();

	static SDL_Texture* wp_texture; //white pawn itd.
	static SDL_Texture* bp_texture;
	static SDL_Texture* wn_texture;
	static SDL_Texture* bn_texture;
	static SDL_Texture* wb_texture;
	static SDL_Texture* bb_texture;
	static SDL_Texture* wr_texture;
	static SDL_Texture* br_texture;
	static SDL_Texture* wq_texture;
	static SDL_Texture* bq_texture;
	static SDL_Texture* wk_texture;
	static SDL_Texture* bk_texture;

	static void loadImages();
};