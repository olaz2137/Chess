#include "Window.h"

#include <iostream>


Window::Window(const std::string &cwindow_title, int cwidth, int cheight)
	:window_title(cwindow_title), width(cwidth), height(cheight)
{
	if (!init()) 
	{
		closed = true;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Could not initalize SDL.\n ";
		return 1;
	}

	window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	// Check if the window was successfully created
	if (window == nullptr)
	{
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return 1;
	}

	return true;

}

void Window::pollEvents()
{
	SDL_Event windowEvent;
	if (SDL_PollEvent(&windowEvent))
	{
		if (SDL_QUIT == windowEvent.type)
		{
			closed = true;
		}
	}
}
