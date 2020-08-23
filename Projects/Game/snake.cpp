/*
 * Snake.cpp
 *
 *  Created on: 22-Aug-2020
 *      Author: Abbie
 */
#include <iostream>
#include <conio.h>
#include <string.h>
//#include <Windows.h>
using namespace std;
bool gameOver;
const int height = 20;
const int width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char input,prevInput;
enum eDirections
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};
eDirections dir;

void Setup()
{
	input=0;
	prevInput=0;
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
    memset(tailX,0,sizeof(tailX));
    memset(tailY,0,sizeof(tailX));
	nTail=0;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout<<endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if(j == 0)
			{
				cout << "#";
			}
			if(i == y && j == x)
				cout<<"O";
			else if(i == fruitY && j == fruitX)
			{
				cout<<"F";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if( j == width - 1 )
			{
				cout << "#";
			}

		}
		cout<<endl;
	}
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout<<endl;

	cout <<" Score = "<<score;
}

void Input()
{
	if(_kbhit())
	{
		bool dirchange = true;
		input = _getch();
		if(prevInput == 'w' || prevInput == 's')
		{
			if (input == 'w' || input == 's')
			{
				prevInput=input;
				return;
			}
		}
		if(prevInput == 'a' || prevInput == 'd')
		{
			if (input == 'a' || input == 'd')
			{
				prevInput=input;
				return;
			}
		}
		switch(input)
		{
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver =true;
			break;
		}
		prevInput=input;
	}
}

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
    case STOP:
        break;
	}
	//if( x < 0 || x >= width || y < 0 || y >=height)
		//gameOver=true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    for(int k=0 ; k<nTail ; k++)
        if(x == tailX[k] && y == tailY[k])
            gameOver=true;
	if(x == fruitX && y == fruitY)
	{
		fruitX = rand() % width;
		fruitY = rand() % height;
		score+=10;
		nTail++;
	}
}

int main()
{
    L1:
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		logic();
	}
	char ch =0;
	do
    {
        Draw();
        cout <<endl<< "   GAME OVER   "<< endl;
        cout <<endl<<endl;
        cout<<"Press 'x' to exit the game and y for new game :_ ";
        ch=getch();
        if (ch == 'y')
            break;

    }while(ch != 'x');
    if(ch == 'y')
        goto L1;
	return 0;
}
