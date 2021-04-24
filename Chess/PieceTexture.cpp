#include "PieceTexture.h"
#include "Game.h"
#include "SDL_image.h"

SDL_Texture* PieceTexture::wp_texture;
SDL_Texture* PieceTexture::bp_texture;
SDL_Texture* PieceTexture::wn_texture;
SDL_Texture* PieceTexture::bn_texture;
SDL_Texture* PieceTexture::wb_texture;
SDL_Texture* PieceTexture::bb_texture;
SDL_Texture* PieceTexture::wr_texture;
SDL_Texture* PieceTexture::br_texture;
SDL_Texture* PieceTexture::wq_texture;
SDL_Texture* PieceTexture::bq_texture;
SDL_Texture* PieceTexture::wk_texture;
SDL_Texture* PieceTexture::bk_texture;
PieceTexture::~PieceTexture()
{
	SDL_DestroyTexture(wp_texture);
	SDL_DestroyTexture(bp_texture);
	SDL_DestroyTexture(wn_texture);
	SDL_DestroyTexture(bn_texture);
	SDL_DestroyTexture(wb_texture);
	SDL_DestroyTexture(bb_texture);
	SDL_DestroyTexture(wr_texture);
	SDL_DestroyTexture(br_texture);
	SDL_DestroyTexture(wq_texture);
	SDL_DestroyTexture(bq_texture);
	SDL_DestroyTexture(wk_texture);
	SDL_DestroyTexture(bk_texture);
}

void PieceTexture::loadImages()
{
	SDL_Surface* image;

	image = IMG_Load("Images/wp.png");
	wp_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/bp.png");
	bp_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/wn.png");
	wn_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/bn.png");
	bn_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/wb.png");
	wb_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/bb.png");
	bb_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/wr.png");
	wr_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/br.png");
	br_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/wq.png");
	wq_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/bq.png");
	bq_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/wk.png");
	wk_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	image = IMG_Load("Images/bk.png");
	bk_texture = SDL_CreateTextureFromSurface(Game::renderer, image);

	SDL_FreeSurface(image);
}
