#pragma once

#include <utility>
#include <iostream>

#include <SDL.h>
#include "Ball.h"

class Game
{
	unsigned		_win_width;
	unsigned		_win_height;
	SDL_Window*		_window;
	SDL_Surface*	_screen_surface;

 public:
	SDL_Renderer*	render;
	SDL_Event		event;
	const char*		win_name;

					Game(unsigned win_width,
						unsigned win_height,
						const char* win_name);
 
					~Game();

	// copy constructor
					Game(const Game& other);
	
	// move constructor
					Game(Game&& other) noexcept;
 
	// copy assignment
	Game&			operator=(const Game& other);

	// move assignment
	Game&			operator=(Game&& other) noexcept;
};
