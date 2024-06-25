#include<iostream>
#include<conio.h>
#include<Windows.h>

#include "utils.h"
#include "timekeeper.h"

int main() {
	
	Timekeeper* tk = new Timekeeper;
	bool run = false;
	bool end = false;

	tk->init_clock();

	gotoxy(15, 0);
	std::cout << "'i' -> Iniciar";
	gotoxy(15, 1);
	std::cout << "'s' -> Terminar";
	gotoxy(15, 2);
	std::cout << "'p' -> Pauser/Resumir";
	gotoxy(15, 3);
	std::cout << "'l' -> Vuelta";
	gotoxy(15, 4);
	std::cout << "'q' -> Salir";
	
	while (!end) {
		while (!run) {
			if (_kbhit()) {
				const char key = _getch();
				if (key == 'q') {
					end = true;
					break;
				}

				if (key == 'i') {
					tk->start();
					run = true;
					break;
				}

			}
		}

		while (run) {
			tk->run();
			if (_kbhit()) {
				const char key = _getch();
				if (key == 'q') {
					end = true;
					break;
				}

				if (key == 's') {
					tk->stop();
					run = false;
					break;
				}

				if (key == 'p') {
					tk->pause();
					break;
				}

				if (key == 'l') {
					tk->lap();
					break;
				}
			}
		}
	}

	gotoxy(0, 7);

	return 0;
}