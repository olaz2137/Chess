#pragma once
#include <string>
#include "SDL.h"

class Window 
{
public:
	Window(const std::string &window_title, int width, int height);
	~Window();

	void pollEvents();
	inline bool isClosed() const { return closed; }


private:
	std::string window_title;
	int width = 800;
	int height = 600;
	bool closed = false;

	bool init();

	SDL_Window* window = nullptr;
};


