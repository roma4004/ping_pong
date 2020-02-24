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
	SDL_Renderer*	render;
public:
	SDL_FRect		pos;
	SDL_FRect		edge = { 0, 0, 640, 480 }; //todo: assign in constructor

					GameObject(SDL_Renderer* render_, SDL_FRect pos_);
	virtual			~GameObject() noexcept;
	virtual bool	move(char dirrection) const;

	virtual void	draw() const;
};
