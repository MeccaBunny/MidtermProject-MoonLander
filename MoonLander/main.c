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

#include"physic.h"
#include "moon.h"
#include "moonlander.h"
#include "ex.h"
#include "VisualTool.h"
#include "test.h"


int* ex;
int* ey;
double* ez;
//double screen[18][77] = { 0, };

int main()
{
	screenTestV1();

	//int psize = randint(50,200);
	//ex = malloc(sizeof(int) * 100);
	//ey = malloc(sizeof(int) * 100);
	//
	//for (int i = 0; i < 100; i++)
	//{
	//	ex[i] = randint(5, 995);
	//	ey[i] = randint(5, 995);
	//}

	return 0;
}

