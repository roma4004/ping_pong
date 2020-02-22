#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
	unsigned		score = 0;
	SDL_Color		_color = { 255, 0, 0, 0 };
public:
	float			_speed = 40;

	Player(SDL_Renderer* render_, SDL_FRect pos_)
	: GameObject::GameObject(render_, pos_)
	{

	};
	bool			move(char dirrection)
	{
		float s = _speed;

		if		(dirrection == 'U' && winEdge.y < pos.y			- s	) { pos.y -= s;							return (true); }
		else if	(dirrection == 'U' && winEdge.y < pos.y				) { pos.y = winEdge.y			+ 10;	return (true); }
		if      (dirrection == 'L' && winEdge.x < pos.x         - s	) { pos.x -= s;							return (true); }
		else if	(dirrection == 'L' && winEdge.x < pos.x				) { pos.x = winEdge.x			+ 10;	return (true); }
		if		(dirrection == 'D' && winEdge.h > pos.y + pos.h + s	) { pos.y += s;							return (true); }
		else if	(dirrection == 'D' && winEdge.h > pos.y + pos.h		) { pos.y = winEdge.h - pos.h	- 10;	return (true); }
		if		(dirrection == 'R' && winEdge.w > pos.x + pos.w + s	) { pos.x += s;							return (true); }
		else if	(dirrection == 'R' && winEdge.w > pos.x + pos.w		) { pos.x = winEdge.x - pos.w	- 10;	return (true); }
		return (false);
	}
};