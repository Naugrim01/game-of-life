#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

//functions:
bool isRight(); // validation
void fill_array(bool t[128][72], int x, int y, int a);
void show_array(bool t[128][72], int x, int y);
void life_step(bool t[128][72], int x, int y);

