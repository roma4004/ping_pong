#include "GameObject.h"

				GameObject::GameObject(SDL_Renderer* render_, SDL_FRect pos_)
				:
				render(render_), pos(pos_) { }

				GameObject::~GameObject() noexcept { }

void			GameObject::draw() const {
	SDL_SetRenderDrawColor(render, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderFillRectF(render, &pos);
	SDL_RenderDrawRectF(render, &pos);
}

bool			GameObject::move(char dirrection) const {
	return (false); 
}