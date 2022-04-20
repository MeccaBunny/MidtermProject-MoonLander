/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
* 
* todo:
* 
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
#include "test.h"

char msg1[] = "Tom: Reporting for duty.                                      ";
char msg2[] = "Tom: Major Tom to ground control. Moon is AMAZING!            ";
char msg3[] = "Tom: Planet Earth is blue and there is nothing I can do.      ";
char* msgs[] = { msg1, msg2, msg3 };

char* getPilotMSG()
{
	int i = randint(0, 2);
	return msgs[i];
}

int* ex;
int* ey;
double* ez;
//double screen[18][77] = { 0, };

void getSurface(double gx, double gy, int psize)
{
	textcolor(7);
	double x = gx;
	double y = gy;
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
}

int main()
{
	int psize = randint(50, 200);
	ex = malloc(sizeof(int) * 100);
	ey = malloc(sizeof(int) * 100);

	for (int i = 0; i < 100; i++)
	{
		ex[i] = randint(5, 995);
		ey[i] = randint(5, 995);
	}

	double t = clock();
	double dt = 0;
	double starting_time = t;

	double x = 553;
	double y = 234;
	double h = 0;
	double dx = 1;
	double dy = 1;
	


	MoonLander_SpaceshipInit();

	MoonLander_coordinate.DDZ = -10/6;

	gotoxy(1, 20);
	char* msg = getPilotMSG();
	printf("%s", msg);
	double msgt = 0;
	double mvt = 0;

	while (1)
	{
		dt = (double)clock() - t;
		t = clock();
		MoonLander_phsics(dt);

		if (x < 100)
		{
			dx = 1;
		}
		if (900 < x)
		{
			dx = -1;
		}
		if (y < 100)
		{
			dy = 1;
		}
		if (900 < y)
		{
			dy = -1;
		}

		mvt += dt;
		if (mvt > 30)
		{
			x += dx*mvt*0.01;
			y += dy*mvt*0.01;
			mvt = 0;
		}

		getSurface(x, y, psize);
		
		prtScreen();
		setscreen();

		textcolor(7);
		gotoxy(1, 5);
		printf("x:%03lf", x);
		gotoxy(1, 7);
		gotoxy(1, 7);
		printf("y:%03lf", y);
		gotoxy(1, 9);
		printf("z:%03lf", MoonLander_coordinate.Z);
		gotoxy(1, 11);
		printf("roll:%03lf", MoonLander_coordinate.Roll);
		gotoxy(1, 13);
		printf("yaw:%03lf",MoonLander_coordinate.Yaw);
		gotoxy(1, 15);
		printf("pitch:%03lf",MoonLander_coordinate.Pitch);
		
		msgt += dt;
		if (msgt > 5000)
		{
			gotoxy(1, 20);
			char* msg = getPilotMSG();
			printf("%s", msg);
			msgt = 0;
		}

		textcolor(14);

		Sleep(1);
	}

	end();

	return 0;
}