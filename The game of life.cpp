// The game of life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

void fill_array(int t[30][90], int x, int y);
void show_array(int t[30][90], int x, int y);

int field[30][90];

int main()
{

    fill_array(field, 30, 90);
    show_array(field, 30, 90);
}

void fill_array(int t[30][90], int x, int y)
{
    srand(time(nullptr));
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            t[i][j] = rand() % 20;
        }
    }

}

void show_array(int t[30][90], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if(t[i][j]!=0)
                std::cout << ' ';
            else
                std::cout << 0;


        }
        std::cout << '\n';

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
