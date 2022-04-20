#include<windows.h>

#include"VisualTool.h"

const int w = 100;
const int h = 23;
double screen[18][77] = { 0, };

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void frame()
{
	//frame
	textcolor(14);

	gotoxy(0, 0);
	for (int i = 0; i < w; i++)
		printf("*");
	for (int i = 1; i <= h; i++)
	{
		gotoxy(0, i);
		printf("*");
		gotoxy(w - 1, i);
		printf("*");
	}
	gotoxy(0, h);
	for (int i = 0; i < w; i++)
		printf("*");

	gotoxy(0, h - 4);
	for (int i = 0; i < w; i++)
		printf("*");

	for (int i = 1; i <= h - 4; i++)
	{
		gotoxy(20, i);
		printf("*");
	}

	gotoxy(0, 4);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 6);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 8);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 10);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 12);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 14);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 16);
	for (int i = 0; i < 20; i++)
		printf("*");
}

void prtdata()
{
	textcolor(7);

	gotoxy(1, 1);
	printf("Moon Lander");
	gotoxy(1, 2);
	printf("중간 프로젝트");
	gotoxy(1, 3);
	printf("박영준2021042010");

	gotoxy(1, 5);
	printf("x:");

	gotoxy(1, 7);
	printf("y:");

	gotoxy(1, 9);
	printf("z:");

	gotoxy(1, 11);
	printf("roll:");

	gotoxy(1, 13);
	printf("yaw:");

	gotoxy(1, 15);
	printf("pitch:");
}


void prtAscii(double k)
{
	if (k > 0.9)
	{
		printf("@");
	}
	else if (k > 0.8)
	{
		printf("&");
	}
	else if (k > 0.7)
	{
		printf("B");
	}
	else if (k > 0.6)
	{
		printf("a");
	}
	else if (k > 0.5)
	{
		printf("*");
	}
	else if (k > 0.4)
	{
		printf("=");
	}
	else if (k > 0.3)
	{
		printf("-");
	}
	else if (k > 0.2)
	{
		printf(";");
	}
	else if (k > 0.1)
	{
		printf("'");
	}
	else
	{
		printf(".");
	}
}

void prtScreen()
{
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 77; j++)
		{
			gotoxy(j + 22, i + 1);
			prtAscii(screen[i][j]);
		}
	}
}

void setscreen()
{
	frame();
	prtdata();

}

void screen_setdata(int x, int y, double data)
{
	screen[y][x] = data;
}













//
//MsgBox* BoxList;
//
//void BoxManager_init(MsgBox* box)
//{
//	/*
//	* BoxList = realloc(n+1)
//	*/
//}
//
//void BoxManager_stack(MsgBox* box, char* msg)
//{
//	/*
//	* msg = malloc(msgbox)
//	* lastnode -> next = msg
//	*  
//	* 
//	*/
//}
//
//void BoxManager_end(MsgBox* box)
//{
//	free(BoxList);
//}
//
//void Box_show(MsgBox* box)
//{
//	int x = box->x;
//	int y = box->y;
//	int w = box->width;
//	int h = box->height;
//	Msg* bmsg = box->msg;
//
//	gotoxy(x, y + 0); printf("*"); for (int i = 0; i < w; i++) printf("*");
//	for (int i = 1; i < h; i++)
//	{
//		gotoxy(x, y + i); printf("*");
//		if (bmsg != NULL)
//		{
//			printf("%s", bmsg->data);
//			bmsg = bmsg->next;
//		}
//		gotoxy(x + w, y + i); printf("*");
//	}
//	gotoxy(x, y + h); printf("*"); for (int i = 0; i < w; i++) printf("*");
//}
//
//
//
//void BoxManager_mainloop()
//{
//	int size = sizeof(*BoxList)/sizeof(MsgBox);
//	for (int i = 0; i < size; i++)
//		Box_show(&BoxList[i]);
//}
//void Box_stackMsg(MsgBox* box, char* s)
//{
//	Msg m;
//	for (int i = 0; i < strlen(s); i++)
//		m.data[i] = s[i];
//	
//}
//void Box_clearMsg(MsgBox* box)
//{
//	for (int i = 0; i < strlen(box->msg->data); i++)
//		box->msg->data[i] = '\0';
//}
//