/**************************************************************
* testing codes
* 
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"physic.h"
#include "moon.h"
#include "moonlander.h"
#include "ex.h"
#include "VisualTool.h"
#include"test.h"

void fallingTest() //testing acceleration of phsic module.
{
	system("color 1f");
	srand((unsigned int)time(NULL)); t = clock(); double starting_time = t;
	MoonLander_SpaceshipInit();
	MoonLander_coordinate.DDZ = -10;

	int i = 0;
	while (1)
	{
		if (i > 3000) break;
		dt = (double)clock() - t; t = clock(); MoonLander_phsics(dt);
		printf("%d  \t  runtime: %lf(s)  \t  rocket's z coordinate: %f(m)  \n", i, (double)(clock() - starting_time) / 1000, MoonLander_coordinate.Z);
		Sleep(1);
		i++;
	}
}

void screenTestV1()
{
	int x = 5;
	int y = 5;
	int dx = 1;
	int dy = 1;
	while (1)
	{
		screen_setdata(x, y, 0);
		if (x < 2)
		{
			dx = 1;
		}
		if (75 < x)
		{
			dx = -1;
		}
		if (y < 2)
		{
			dy = 1;
		}
		if (15 < y)
		{
			dy = -1;
		}

		x += dx;
		y += dy;
		screen_setdata(x, y, 0.95);

		setscreen();
		prtScreen();

		textcolor(7);
		gotoxy(1, 5);
		printf("x:%02d", x);
		gotoxy(1, 7);
		gotoxy(1, 7);
		printf("y:%02d", y);
		gotoxy(1, 9);
		printf("z:");
		gotoxy(1, 11);
		printf("roll:");
		gotoxy(1, 13);
		printf("yaw:");
		gotoxy(1, 15);
		printf("pitch:");
		textcolor(14);

		Sleep(10);
	}
	end();

}