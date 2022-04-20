#ifndef VISUALTOOL_H
#define VISUALTOOL_H

void textcolor(int colorNum);
void gotoxy(int x, int y);
void frame();
void prtdata();
void prtAscii(double k);
void prtScreen();
void setscreen();
void screen_setdata(int x, int y, double data);

//
//typedef struct Msg {
//	char data[100];
//	struct Msg* next;
//} Msg;
//
//typedef struct MsgBox {
//	int x;
//	int y;
//	int width;
//	int height;
//	Msg *msg;
//} MsgBox;
//
//void gotoxy(int x, int y);
//
//void BoxManager_init(MsgBox* box);
//void BoxManager_stack(MsgBox* box, char* msg);
//void BoxManager_end(MsgBox* box);
//
//void Box_show();
//void BoxManager_mainloop();
//void Box_stackMsg(MsgBox* box, char* s);
//void Box_clearMsg(MsgBox* box);
#endif