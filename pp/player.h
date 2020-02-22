#pragma once

#include "GameObject.h"
#include "Ball.h"

class Player :
	virtual public GameObject
{
	unsigned		score = 0;

	SDL_Color		_color = { 255, 0, 0, 0 };

public:
	bool			autoPilot = true;
	SDL_FRect		ballPos;
	float			_speed = 40;

					Player(SDL_Renderer* render_,
						SDL_FRect pos_);

					~Player();

	bool			move(char dirrection);
};