#pragma once

#include "GameObject.h"
#include "Player.h"


class Ball :
	public GameObject
{
	float			xSpeed = 0.2f;
	float			ySpeed = 0.2f;
	t_fvec			center = { edge.w / 2, edge.h / 2 };

	SDL_Color		_color = { 0, 0, 255, 0 };

	GameObject&		_playerLeft;
	GameObject&		_playerRight;

public:
					Ball(SDL_Renderer* render, 
						SDL_FRect pos_, 
						GameObject& playerLeft,
						GameObject& playerRight);

					~Ball();

	bool			isInRange(float val, float rangeMin, float rangeMax) const;

	bool			isInRectangle(SDL_FRect rect) const;

	void			move();
	void			reset();
};
