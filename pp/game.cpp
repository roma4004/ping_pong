#include "Game.h"

				Game::Game(unsigned win_width,
					unsigned win_height,
					const char* win_name)
				:
					_win_width(win_width = 640),
					_win_height(win_height = 480),
					win_name(win_name)
				{
					if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
					{
						_window = SDL_CreateWindow(win_name,
							SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED,
							_win_width,
							_win_height,
							SDL_WINDOW_SHOWN);
						_screen_surface = SDL_GetWindowSurface(_window);
						render = SDL_CreateRenderer(_window,
							-1,
							SDL_RENDERER_ACCELERATED);
					}
					else
					{
						std::cout
							<< "SDL initialization failed. SDL Error: "
							<< SDL_GetError();
					}
				}
				Game::~Game() {
					SDL_DestroyWindow(_window);
					_window = NULL;

					SDL_DestroyRenderer(render);
					render = NULL;
					SDL_Quit();
				}

// copy constructor
				Game::Game(const Game& other)
					:
				Game(other._win_width, other._win_height, other.win_name) {}

// move constructor
				Game::Game(Game&& other) noexcept
				:
				win_name(std::exchange(other.win_name, nullptr)) {}

// copy assignment
Game&			Game::operator=(const Game& other) {
	return *this = Game(other);
}

// move assignment
Game&			Game::operator=(Game&& other) noexcept
{
	std::swap(win_name, other.win_name);
	return *this;
}
