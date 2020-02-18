#pragma once

#include <utility>
#include <iostream>

#include <SDL.h>

class game
{
	unsigned		_win_width = 640;
	unsigned		_win_height = 480;
	SDL_Window*		_window;
	SDL_Surface*	_screen_surface;
 public:
	SDL_Renderer*	render;
	SDL_Event		event;
	const char*		win_name;

	game(unsigned win_width, unsigned win_height, const char* win_name)
    : _win_width(win_width), _win_height(win_height), win_name(win_name)
    {
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		{
			_window = SDL_CreateWindow(win_name,
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				_win_width, _win_height,
				SDL_WINDOW_SHOWN);
			_screen_surface = SDL_GetWindowSurface(_window);
			render = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
		}
		else
		{
			std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
		}
    }
 
    ~game() {
		//delete[] _win_name; 
		SDL_DestroyWindow(_window);
		_window = NULL;

		SDL_DestroyRenderer(render);
		render = NULL;
		SDL_Quit(); 
	}

	// copy constructor
	game(const game& other) : game(other._win_width, other._win_height, other.win_name) {}
	


	// move constructor
	game(game&& other) noexcept : win_name(std::exchange(other.win_name, nullptr)) {}
 
	// copy assignment
	game& operator=(const game& other) { return *this = game(other); }

	// move assignment
	game& operator=(game&& other) noexcept
    {
        std::swap(win_name, other.win_name);
        return *this;
    }
};

