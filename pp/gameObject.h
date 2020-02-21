#pragma once

#include <SDL.h>

typedef struct		s_vector_int
{
	int				x;
	int				y;
}					t_ivec;

typedef struct		s_vector_float
{
	float			x;
	float			y;
}					t_fvec;

class GameObject
{

	SDL_Color		_color = { 0, 0, 0, 0 };
	float			_speed = 10;

public:
	SDL_Rect		selfRect;
	SDL_Renderer*	render;
	t_fvec			moveLimitsMin = { 0, 0 };
	t_fvec			moveLimitsMax = { 640, 480 }; //todo: assign in constructor

	t_fvec			size = { 20, 40 };
	t_fvec			pos = { 10, 10 };//todo: get set

	GameObject(SDL_Renderer* render)
		: render(render)
	{

	};
	//~gameobject()
	//{
	//	render = nullptr;
	//};
	bool			move(char dirrection)
	{
		if (dirrection == 'w'
		&& moveLimitsMin.y < pos.y           - _speed) { pos.y -= _speed; return (true); }
		if (dirrection == 'a'
		&& moveLimitsMin.x < pos.x           - _speed) { pos.x -= _speed; return (true); }
		if (dirrection == 's'
		&& moveLimitsMax.y > pos.y + size.y + _speed) { pos.y += _speed; return (true); }
		if (dirrection == 'd'
		&& moveLimitsMax.x > pos.x + size.x + _speed) { pos.x += _speed; return (true); }
		return (false);

	}

	void			draw() {
		selfRect = {
			(int)(pos.x),
			(int)(pos.y),
			(int)(size.x),
			(int)(size.y)
		};

		SDL_SetRenderDrawColor(render, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(render, &selfRect);

		SDL_RenderDrawRect(render, &selfRect);
	}
};

