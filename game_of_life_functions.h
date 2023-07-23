#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

//functions:
bool isRight(); // validation
void fill_array(bool t[30][90], int x, int y, int a);
void show_array(bool t[30][90], int x, int y);
void life_step(bool t[30][90], int x, int y);
void game_of_life();
