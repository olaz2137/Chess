#include "Window.h"


int main(int argc, char* argv[])
{
    Window window("Szachy", 800, 600);
    while(!window.isClosed())
    {
        window.pollEvents();
    }


    return 0;
}