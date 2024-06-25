#include<Windows.h>
#include<iostream>

#include "utils.h"

void gotoxy(int x, int y) {
	HANDLE cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cCoords{};
	cCoords.X = x;
	cCoords.Y = y;

	SetConsoleCursorPosition(cHandle, cCoords);
}

void clear_screen(int rows) {
	for (size_t i = 0; i < rows; i++) {
		gotoxy(0, i);
		std::cout << "            ";
	}
}