/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
* 
* todo:
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

void testing();

int main()
{
	testing();
	
	
	return 0;
}

void testing()
{
	system("color 1f");
	srand((unsigned int)time(NULL)); t = clock(); double starting_time = t;
	MoonLander_SpaceshipInit();

	MoonLander_coordinate.DDZ = -10;

	int i = 0;
	while (1)
	{
		if (i > 3000) { break; }
		dt = (double)clock() - t; t = clock(); MoonLander_phsics(dt);

		printf("%d  \t  runtime: %lf(s)  \t  rocket's z coordinate: %f(m)  \n", i, (double)(clock() - starting_time) / 1000, MoonLander_coordinate.Z);

		Sleep(1);
		i++;
	}
	endMoon();
}