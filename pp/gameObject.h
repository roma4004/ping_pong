#pragma once

#include <SDL.h>

typedef struct		s_vector_int
{
	int				x;
	int				y;
}					t_ivec;

class gameObject
{
	t_ivec			_moveLimitsMin = { 0, 0 };
	t_ivec			_moveLimitsMax = { 640, 480 }; //todo: assign in constructor
	t_ivec			_size = { 20, 40 };
	SDL_Color		_color = { 0, 0, 0, 0 };
	unsigned		_speed = 10;
	SDL_Renderer*	_render;

	SDL_Rect		_selfRect;
public:

	t_ivec			pos = { 10, 10 };//todo: get set

	gameObject(SDL_Renderer* render)
		: _render(render)
	{

	};
	//~gameobject()
	//{
	//	render = nullptr;
	//};
	bool			move(char dirrection)
	{
		if (dirrection == 'w'
		&& _moveLimitsMin.y < pos.y           - _speed) { pos.y -= _speed; return (true); }
		if (dirrection == 'a'
		&& _moveLimitsMin.x < pos.x           - _speed) { pos.x -= _speed; return (true); }
		if (dirrection == 's'
		&& _moveLimitsMax.y > pos.y + _size.y + _speed) { pos.y += _speed; return (true); }
		if (dirrection == 'd'
		&& _moveLimitsMax.x > pos.x + _size.x + _speed) { pos.x += _speed; return (true); }
		return (false);

	}

	void			draw() {
		_selfRect = { pos.x, pos.y, _size.x, _size.y };

		SDL_SetRenderDrawColor(_render, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(_render, &_selfRect);

		SDL_RenderDrawRect(_render, &_selfRect);
	}
};

