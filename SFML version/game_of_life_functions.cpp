#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>
#include "game_of_life_functions.h"


bool isRight()
{
    if (std::cin.rdstate())
    {
        std::cin.clear();
        std::cin.ignore(1024, '\n');

        system("cls");

        return false;
    }
    system("cls");

    return true;
}

void fill_array(bool t[128][72], int x, int y, int a)
{
    srand(time(nullptr));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if ((rand() % 100) < a)
                t[i][j] = true;
            else
                t[i][j] = false;
        }
    }

}

void show_array(bool t[128][72], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (t[i][j] != 0)
                std::cout << '+';
            else
                std::cout << ' ';


        }
        std::cout << '\n';

    }

}

void life_step(bool t[128][72], int x, int y)
{
    bool t2[128][72];
    int sum;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            sum = 0;
            for (int s = (i - 1); s < i + 2; s++)
            {
                for (int u = (j - 1); u < j + 2; u++)
                {
                    if ((s == i) && (u == j))
                        continue;
                    else
                        sum += t[(x + s) % x][(y + u) % y]; //modulo is allow to not read memory except array area
                }
            }


            if (sum == 3)
                t2[i][j] = true;
            else if (sum == 2)
                t2[i][j] = t[i][j];
            else
                t2[i][j] = false;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            t[i][j] = t2[i][j];

        }

    }
}