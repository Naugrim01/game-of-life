// The game of life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

void fill_array(bool t[30][90], int x, int y, int a);
void show_array(bool t[30][90], int x, int y);
void life_step(bool t[30][90], int x, int y);

bool field[30][90];
int a = 5;

int main()
{
    //char decide;
    std::cout << "how much life? 0-100%\n";
    std::cin >> a;
    system("cls");
    fill_array(field, 30, 90, a);
    show_array(field, 30, 90);
    system("pause");
    system("cls");

    for (;;)
    {
        life_step(field, 30, 90);
        show_array(field, 30, 90);
        system("pause");
        system("cls");
    }
}

void fill_array(bool t[30][90], int x, int y, int a)
{
    srand(time(nullptr));
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            if ((rand() % 100) <= a)
                t[i][j] = true;
            else
                t[i][j] = false;
        }
    }

}

void show_array(bool t[30][90], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if(t[i][j]!=0)
                std::cout << '+';
            else
                std::cout << ' ';


        }
        std::cout << '\n';

    }
    
}

void life_step(bool t[30][90], int x, int y)
{
    bool t2[30][90];
    int sum;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i != 0 && i != x - 1 && j != 0 && j != y - 1)
            {
                sum = 0;
                sum = t[i - 1][j - 1] + t[i][j - 1] + t[i + 1][j - 1] + t[i - 1][j] + t[i + 1][j] + t[i - 1][j + 1] + t[i][j + 1] + t[i + 1][j + 1];
                if (sum < 4 && sum > 1)
                    t2[i][j] = true;
                else
                    t2[i][j] = false;
            }
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
