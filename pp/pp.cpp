// pp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Game.h"
#include "Ball.h"
#include "Player.h"

void	clearScreen(const Game& window)
{
	SDL_SetRenderDrawColor(window.render, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(window.render);
}

int main(int argc, char *argv[])
{
	Game		window	= Game(640, 480, "PP");
	Player		playerL	= Player(window.render, { 10, 10, 20, 100 } );
	playerL.autoPilot = false;
	Player		playerR	= Player(window.render, { 610, 10, 20, 100 } );
	Ball		ball	= Ball(window.render, { 320, 240, 10, 10 }, playerL, playerR);


	bool		running	= true;

	while (running) {
		clearScreen(window);
		while (SDL_PollEvent(&window.event)) {
			switch (window.event.type)
			{
			case SDL_KEYDOWN:
				printf("key %s is pressed!\n",
					SDL_GetKeyName(window.event.key.keysym.sym));
				
				if (window.event.key.keysym.sym == SDLK_ESCAPE) { running = false; }

				if (window.event.key.keysym.sym == SDLK_w		) { playerL.move('U'); }
			//  if (window.event.key.keysym.sym == SDLK_a		) { playerL.move('L'); }
				if (window.event.key.keysym.sym == SDLK_s		) { playerL.move('D'); }
			//  if (window.event.key.keysym.sym == SDLK_d		) { playerL.move('R'); }

				if (window.event.key.keysym.sym == SDLK_UP		) { playerR.move('U'); }
			//	if (window.event.key.keysym.sym == SDLK_LEFT	) { playerR.move('L'); }
				if (window.event.key.keysym.sym == SDLK_DOWN	) { playerR.move('D'); }
			//	if (window.event.key.keysym.sym == SDLK_RIGHT	) { playerR.move('R'); }
				break;
			case SDL_QUIT:
				running = false;
			}
		}

		ball.move();
		ball.draw();
		playerL.ballPos = ball.pos;
		playerR.ballPos = ball.pos;
		playerL.move('A');	// A is for autoPilot
		playerR.move('A');	// A is for autoPilot
		playerL.draw();
		playerR.draw();
		SDL_RenderPresent(window.render);
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
