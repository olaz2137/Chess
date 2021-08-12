#include "Game.h"
#include "BoardRect.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main(int argc, char* argv[]){

    Uint32 frameStart, frameTime;

    TheGame::Instance()->init("Szachy", BoardRect::board_len, BoardRect::board_len);
    while (!TheGame::Instance()->isClosed()) {

        frameStart = SDL_GetTicks();

        TheGame::Instance()->render();
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) SDL_Delay((int)(DELAY_TIME - frameTime));
    }

    return 0;
}