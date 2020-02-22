
#include "Ball.h"

				Ball::Ball(SDL_Renderer* render,
					SDL_FRect pos_,
					GameObject& playerLeft,
					GameObject& playerRight)
					:
					GameObject::GameObject(render, pos_),
					_playerLeft(playerLeft),
					_playerRight(playerRight) {
				}

				Ball::~Ball() { }

bool			Ball::isInRange(float val, float rangeMin, float rangeMax) const
{
	if (rangeMin < val && val < rangeMax)
	{
		return (true);
	}
	return (false);
}

bool			Ball::isInRectangle(SDL_FRect rect) const
{
	if (isInRange(pos.x, rect.x, rect.x + rect.w)
	&& isInRange(pos.y, rect.y, rect.y + rect.h)
	&& isInRange(pos.x + pos.w, rect.x, rect.x + rect.w)
	&& isInRange(pos.y + pos.h, rect.y, rect.y + rect.h))
	{
		return (true);
	}
	return (false);
}
void			Ball::reset()
{
	pos.x = center.x;
	xSpeed = 0.2f;
}

void			Ball::move()
{
	if ((xSpeed			< 0 && isInRectangle(_playerLeft.pos) && _playerLeft.pos.x++)
	|| (xSpeed			> 0 && isInRectangle(_playerRight.pos) && _playerRight.pos.x--))
	{
		xSpeed = -xSpeed * 1.05f;
	}
	if (pos.x < edge.x /*&& _playerRight->score++*/
	|| (pos.x + pos.w > edge.w	/*&& _playerLeft->score++*/))
	{
		reset();
	}
	if (pos.y < edge.y
	|| pos.y > edge.h)
	{
		ySpeed = -ySpeed;
	}
	pos.x += xSpeed;
	pos.y += ySpeed;
}
