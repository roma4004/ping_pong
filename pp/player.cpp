#include "Player.h"

				Player::Player(SDL_Renderer* render_, SDL_FRect pos_)
				:
				GameObject::GameObject(render_, pos_){	}
				
				Player::~Player() {	}

bool			Player::move(char dirrection)
{
	float s = _speed;

	if (autoPilot)
	{
		if (ballPos.y < pos.y)
			dirrection = 'U';
		if (ballPos.y > pos.y + pos.h)
			dirrection = 'D';
	}
	switch(dirrection)
	{
	case 'U':
		if		(edge.y < pos.y 		- s	) { pos.y -= s;						return (true); }
		else if	(edge.y < pos.y				) { pos.y = edge.y + 10;			return (true); }
	break ;
	case 'L':
		if		(edge.x < pos.x 		- s	) { pos.x -= s;						return (true); }
		else if	(edge.x < pos.x				) { pos.x = edge.x + 10;			return (true); }
	break;
	case 'D':
		if		(edge.h > pos.y + pos.h + s	) { pos.y += s;						return (true); }
		else if	(edge.h > pos.y + pos.h		) { pos.y = edge.h - 10 - pos.h;	return (true); }
	break;
	case 'R':
		if		(edge.w > pos.x + pos.w + s	) { pos.x += s;						return (true); }
		else if	(edge.w > pos.x + pos.w		) { pos.x = edge.x - 10 - pos.w;	return (true); }
	break;
	}
	return (false);
}

