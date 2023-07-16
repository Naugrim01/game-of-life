#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>
#include "game_of_life_functions.h"

//variables:
bool field[30][90];
int a = 5;

int main()
{
    //char decide;
    do
    {
        std::cout << "how much life? 0-100%\n";
        std::cin >> a;
        system("cls");
    } while (( a < 0|| a > 100) || !isRight());

    fill_array(field, 30, 90, a);
    show_array(field, 30, 90);
    system("pause");
    system("cls");

    for (;;)
    {
        life_step(field, 30, 90);
        show_array(field, 30, 90);
       // system("pause");
        system("cls");
    }
}

