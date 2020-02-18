// pp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "game.h"
#include "gameObject.h"


void	clearSecreen(const game* lobby)
{
	SDL_SetRenderDrawColor(lobby->render, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(lobby->render);
}

int main(int argc, char *argv[])
{
	game *lobby = new game(640, 480, "PP");
	gameObject* player = new gameObject(lobby->render);

	clearSecreen(lobby);
	t_ivec	playerPos = { 20, 20 };
	SDL_Rect rect1;

	//unsigned rect1Pos = 10;
	//SDL_Rect rect1 = { rect1Pos, 10, 50, 50 };
	//SDL_RenderFillRect(lobby->_render, &rect1);
	//SDL_RenderDrawRect(lobby->_render, &rect1);
	bool running = true;

	while (running) {
		while (SDL_PollEvent(&lobby->event)) {
			switch (lobby->event.type)
			{
			case SDL_KEYDOWN:
				printf("key %s is pressed!\n",
					SDL_GetKeyName(lobby->event.key.keysym.sym));
				if (lobby->event.key.keysym.sym == SDLK_w) { player->move('w'); }
				if (lobby->event.key.keysym.sym == SDLK_a) { player->move('a'); }
				if (lobby->event.key.keysym.sym == SDLK_s) { player->move('s'); }
				if (lobby->event.key.keysym.sym == SDLK_d) { player->move('d'); }

				//SDL_UpdateTexture(env->screen, NULL, env->buff, env->buff_width << 2u);
				//SDL_RenderCopy(env->renderer, env->screen, NULL, NULL);



				clearSecreen(lobby);


				player->draw();
				SDL_RenderPresent(lobby->render);

				break;
			case SDL_QUIT:
				running = false;
			}
		}
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
