
#include "GameObject.h"

class Ball :
	public GameObject
{
	float			xSpeed = 0.42;
	float			ySpeed = 0.42;

public:
	Ball(SDL_Renderer* render)
		: GameObject::GameObject(render)
	{

	};

	void			move()
	{
		if (pos.y < moveLimitsMin.y || pos.y > moveLimitsMax.y)
			ySpeed = -ySpeed;
		
		if (pos.x < moveLimitsMin.x || pos.x > moveLimitsMax.x)
			xSpeed = -xSpeed;

		pos.x += xSpeed;
		pos.y += ySpeed;
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
