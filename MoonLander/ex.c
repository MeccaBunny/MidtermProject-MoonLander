/**************************************************************
* ex
* Some variables and functions which is hard to directly included
* to Moon or Moonlander are very important to express the
* moon landing situation.
* This zone is to imply such variables and functions. But some
* variables and functions could be moved to zone where it seems
* reasonable.
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#include"physic.h"
#include "moon.h"
#include "moonlander.h"
#include "ex.h"

int landed() {
	/*
	* if lander's Z == moonSurface[lander's X, lader's Y]
	*   if lander's orientation == moonSurfaceOrientation
	*     if DX,DY,DZ,DDX,DDY,DDZ < safetyDegree
	*       return 1; // landing complete!
	* else
	*   return 0; // landing failed.
	*/
}

int randint(int s, int e) {
	return rand() % (e - s + 1) + s;
}