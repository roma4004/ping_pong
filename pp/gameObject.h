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
	SDL_Color		_color = { 0, 255, 0, 0 };
public:
	SDL_FRect		pos;
	SDL_Renderer*	render;
	SDL_FRect		winEdge = { 0, 0, 640, 480 };//todo: assign in constructor

	GameObject(SDL_Renderer* render_, SDL_FRect pos_)
	: render(render_), pos(pos_)
	{

	};
	virtual ~GameObject() { };
	virtual bool	move(char dirrection) { return (false); };

	virtual void	draw() {
		SDL_SetRenderDrawColor(render, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRectF(render, &pos);
		SDL_RenderDrawRectF(render, &pos);
	}
};

