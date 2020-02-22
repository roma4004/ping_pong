
#include "GameObject.h"

class Ball :
	public GameObject
{
	GameObject*		_playerLeft;
	GameObject*		_playerRight;
	float			xSpeed = 0.1f;
	float			ySpeed = 0.1f;
	SDL_Color		_color = { 0, 0, 255, 0 };

public:
	Ball(SDL_Renderer* render, 
		SDL_FRect pos_, 
		GameObject* playerLeft, 
		GameObject* playerRight)
	: GameObject::GameObject(render, pos_),
		_playerLeft(playerLeft),
		_playerRight(playerRight)
	{
		
	};

	bool			isInRange(float val, float rangeMin, float rangeMax)
	{
		if (rangeMin < val && val < rangeMax)
		{
			return (true);
		}
		return (false);
	}

	bool			isInRectangle(SDL_FRect rect)
	{
		if (isInRange(pos.x        , rect.x, rect.x + rect.w)
		&&  isInRange(pos.y        , rect.y, rect.y + rect.h)
		&&  isInRange(pos.x + pos.w, rect.x, rect.x + rect.w)
		&&  isInRange(pos.y + pos.h, rect.y, rect.y + rect.h))
		{
			return (true);
		}
		return (false);
	}

	void			move()
	{
		if ((xSpeed < 0 && isInRectangle(_playerLeft->pos ))
		||  (xSpeed > 0 && isInRectangle(_playerRight->pos))
		|| (pos.x < winEdge.x /*&& _playerRight->score++*/)
		|| (pos.x > winEdge.w /*&& _playerLeft->score++*/))
		{
			xSpeed = -xSpeed;
			//if (toch left edge) +1 score right player
		}
		if (pos.y < winEdge.y
		|| pos.y > winEdge.h)
		{
			ySpeed = -ySpeed;
		}
		pos.x += xSpeed;
		pos.y += ySpeed;
	}
};
