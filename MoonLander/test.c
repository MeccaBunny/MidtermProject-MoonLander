/**************************************************************
* testing codes
* 
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>

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

void screenTestV2()
{
	int* ex;
	int* ey;

	int psize = randint(50, 200);
	ex = malloc(sizeof(int) * 100);
	ey = malloc(sizeof(int) * 100);

	for (int i = 0; i < 100; i++)
	{
		ex[i] = randint(5, 995);
		ey[i] = randint(5, 995);
	}

	double x = 553;
	double y = 234;
	double dx = 5;
	double dy = 5;

	while (1)
	{
		if (x < 100)
		{
			dx = 5;
		}
		if (900 < x)
		{
			dx = -5;
		}
		if (y < 100)
		{
			dy = 5;
		}
		if (900 < y)
		{
			dy = -5;
		}

		x += dx;
		y += dy;
		for (int a = 0; a < 18; a++)
		{
			for (int b = 0; b < 77; b++)
			{
				double px = x + b;
				double py = y + a;
				double t = 0;
				for (int i = 0; i < psize; i++)
				{
					double q = px - ex[i];
					double w = py - ey[i];
					double r2 = pow(q, 2) + pow(w, 2);

					if (r2 < 10000)
					{
						double tmp = r2 / 1000;
						t += exp(-tmp);
					}
				}
				screen_setdata(b, a, t);
			}
		}
		setscreen();
		prtScreen();

		textcolor(7);
		gotoxy(1, 5);
		printf("x:%03lf", x);
		gotoxy(1, 7);
		gotoxy(1, 7);
		printf("y:%03lf", y);
		gotoxy(1, 9);
		printf("z:");
		gotoxy(1, 11);
		printf("roll:");
		gotoxy(1, 13);
		printf("yaw:");
		gotoxy(1, 15);
		printf("pitch:");
		textcolor(14);

		Sleep(1);
	}

	end();
}