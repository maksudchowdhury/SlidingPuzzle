/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/




# include "iGraphics.h"
#define _CRT_SECURE_NO_WARNINGS

struct image
{
	char imgname[20];
	int x;
	int y;
};
struct image images[9];
int i, posx = 0, posy = 0, tmpid ;
//char filename[11][20] = { "srcS\\0.bmp", "srcS\\1.bmp", "srcS\\2.bmp", "srcS\\3.bmp", "srcS\\4.bmp", "srcS\\5.bmp", "srcS\\6.bmp", "srcS\\7.bmp", "srcS\\8.bmp","srcS\\head.bmp","srcS\\gclip.wav" };
char filename[11][20] = { "srcP\\0.bmp", "srcP\\1.bmp", "srcP\\2.bmp", "srcP\\3.bmp", "srcP\\4.bmp", "srcP\\5.bmp", "srcP\\6.bmp", "srcP\\7.bmp", "srcP\\8.bmp","srcP\\head.bmp","srcP\\gclip.wav" };

bool changekey = true;
char tmpimg[20];
int mposx,  mposy;
bool button = true, runtime = true;
int second = 0, minute = 0, nanosec = 0;
char secs[10], mins[10],nansec[10];
int randdata[9];

/*
	function iDraw() is called again and again by the system.
*/
void imgcords();
void imgarrange();
void iDraw()
{
	
	//place your drawing codes here
	iClear();
	_itoa_s(second, secs, 10);
	_itoa_s(minute, mins, 10);
	_itoa_s(nanosec, nansec, 10);
	iShowBMP(0, 600, filename[9]);
	iSetColor(255, 255, 255);
	iText(290, 650, secs,GLUT_BITMAP_HELVETICA_18);
	iSetColor(255, 255, 255);
	iText(275, 650, ":", GLUT_BITMAP_HELVETICA_18);
	if (second < 10){
		iText(310, 650, ":", GLUT_BITMAP_HELVETICA_18);
		iText(325, 650, nansec, GLUT_BITMAP_HELVETICA_18);

	}
	if (second >9){
		iText(320, 650, ":", GLUT_BITMAP_HELVETICA_18);
		iText(335, 650, nansec, GLUT_BITMAP_HELVETICA_18);

	}
	if (minute < 10){
		iText(255, 650, mins, GLUT_BITMAP_HELVETICA_18);
	}
	if (minute > 9){
		iText(245, 650, mins, GLUT_BITMAP_HELVETICA_18);
	}
	
	changekey = true;
	for (i = 0; i < 9; i++){
		iShowBMP(images[i].x, images[i].y, images[i].imgname);
	}
	iSetColor(255, 255, 255);
	iLine(0, 600, 600, 600);
	iSetColor(0, 0, 0);
	iLine(0, 200, 600, 200);
	iLine(0, 400, 600, 400);
	iLine(200, 0, 200, 600);
	iLine(400, 0, 400, 600);
	if (	strcmp(images[0].imgname, filename[0]) == 0 \
		 && strcmp(images[1].imgname, filename[1]) == 0 \
		 && strcmp(images[2].imgname, filename[2]) == 0 \
		 && strcmp(images[3].imgname, filename[3]) == 0 \
		 && strcmp(images[4].imgname, filename[4]) == 0 \
		 && strcmp(images[5].imgname, filename[5]) == 0 \
		 && strcmp(images[6].imgname, filename[6]) == 0 \
		 && strcmp(images[7].imgname, filename[7]) == 0 \
		 && strcmp(images[8].imgname, filename[8]) == 0 )
	{
		button = false;
		runtime = false;
		//iShowBMP2(0, 0, "src\\gcom.bmp",0);
		iSetColor(255, 255, 255);
		iText(170, 620, "Press 'R' to play another round", GLUT_BITMAP_HELVETICA_18);
	}
}
	
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		strcpy_s(images[0].imgname, filename[0]);
		strcpy_s(images[1].imgname, filename[1]);
		strcpy_s(images[2].imgname, filename[2]);
		strcpy_s(images[3].imgname, filename[3]);
		strcpy_s(images[4].imgname, filename[4]);
		strcpy_s(images[5].imgname, filename[5]);
		strcpy_s(images[6].imgname, filename[6]);
		strcpy_s(images[7].imgname, filename[7]);
		strcpy_s(images[8].imgname, filename[8]);

		//do something with 'q'
	}
	if (key == 'r')
	{
		tmpid = 2;
		runtime = true;
		second = 0;
		minute = 0;
		nanosec = 0;
		changekey = true;
		button = true;
		imgcords();
		imgarrange();
		
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_DOWN && button==true)
	{
		if (tmpid == 0 && changekey == true){
			tmpid = 3;										 //
			strcpy_s(tmpimg, images[0].imgname);
			strcpy_s(images[0].imgname, images[3].imgname);
			strcpy_s(images[3].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 1 && changekey == true){
			tmpid = 4;										 //
			strcpy_s(tmpimg, images[1].imgname);
			strcpy_s(images[1].imgname, images[4].imgname);
			strcpy_s(images[4].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 2 && changekey == true){
			tmpid = 5;										 //
			strcpy_s(tmpimg, images[2].imgname);
			strcpy_s(images[2].imgname, images[5].imgname);
			strcpy_s(images[5].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 3 && changekey == true){
			tmpid = 6;										 //
			strcpy_s(tmpimg, images[3].imgname);
			strcpy_s(images[3].imgname, images[6].imgname);
			strcpy_s(images[6].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 4 && changekey == true){
			tmpid = 7;										 //
			strcpy_s(tmpimg, images[4].imgname);
			strcpy_s(images[4].imgname, images[7].imgname);
			strcpy_s(images[7].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 5 && changekey == true){
			tmpid = 8;										 //
			strcpy_s(tmpimg, images[5].imgname);
			strcpy_s(images[5].imgname, images[8].imgname);
			strcpy_s(images[8].imgname, tmpimg);
			changekey = false;
		}
		
		
	}




	if (key == GLUT_KEY_UP && button == true)
	{
		if (tmpid == 3 && changekey == true){
			tmpid = 0;										 //
			strcpy_s(tmpimg, images[3].imgname);
			strcpy_s(images[3].imgname, images[0].imgname);
			strcpy_s(images[0].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 4 && changekey == true){
			tmpid = 1;										 //
			strcpy_s(tmpimg, images[4].imgname);
			strcpy_s(images[4].imgname, images[1].imgname);
			strcpy_s(images[1].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 5 && changekey == true){
			tmpid = 2;										 //
			strcpy_s(tmpimg, images[5].imgname);
			strcpy_s(images[5].imgname, images[2].imgname);
			strcpy_s(images[2].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 6 && changekey == true){
			tmpid = 3;										 //
			strcpy_s(tmpimg, images[6].imgname);
			strcpy_s(images[6].imgname, images[3].imgname);
			strcpy_s(images[3].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 7 && changekey == true){
			tmpid = 4;										 //
			strcpy_s(tmpimg, images[7].imgname);
			strcpy_s(images[7].imgname, images[4].imgname);
			strcpy_s(images[4].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 8 && changekey == true){
			tmpid = 5;										 //
			strcpy_s(tmpimg, images[8].imgname);
			strcpy_s(images[8].imgname, images[5].imgname);
			strcpy_s(images[5].imgname, tmpimg);
			changekey = false;
		}
		
		
	}
	if (key == GLUT_KEY_RIGHT && button == true)
	{
		if (tmpid == 1 && changekey == true){
			tmpid = 0;										 //
			strcpy_s(tmpimg, images[1].imgname);
			strcpy_s(images[1].imgname, images[0].imgname);
			strcpy_s(images[0].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 2 && changekey == true){
			tmpid = 1;										 //
			strcpy_s(tmpimg, images[2].imgname);
			strcpy_s(images[2].imgname, images[1].imgname);
			strcpy_s(images[1].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 4 && changekey == true){
			tmpid = 3;										 //
			strcpy_s(tmpimg, images[4].imgname);
			strcpy_s(images[4].imgname, images[3].imgname);
			strcpy_s(images[3].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 5 && changekey == true){
			tmpid = 4;										 //
			strcpy_s(tmpimg, images[5].imgname);
			strcpy_s(images[5].imgname, images[4].imgname);
			strcpy_s(images[4].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 7 && changekey == true){
			tmpid = 6;										 //
			strcpy_s(tmpimg, images[7].imgname);
			strcpy_s(images[7].imgname, images[6].imgname);
			strcpy_s(images[6].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 8 && changekey == true){
			tmpid = 7;										 //
			strcpy_s(tmpimg, images[8].imgname);
			strcpy_s(images[8].imgname, images[7].imgname);
			strcpy_s(images[7].imgname, tmpimg);
			changekey = false;
		}
		
	}
	if (key == GLUT_KEY_LEFT && button == true)
	{
		if (tmpid == 0 && changekey == true){
			tmpid = 1;										 //
			strcpy_s(tmpimg, images[0].imgname);
			strcpy_s(images[0].imgname, images[1].imgname);
			strcpy_s(images[1].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 1 && changekey == true){
			tmpid = 2;										 //
			strcpy_s(tmpimg, images[1].imgname);
			strcpy_s(images[1].imgname, images[2].imgname);
			strcpy_s(images[2].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 3 && changekey == true){
			tmpid = 4;										 //
			strcpy_s(tmpimg, images[3].imgname);
			strcpy_s(images[3].imgname, images[4].imgname);
			strcpy_s(images[4].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 4 && changekey == true){
			tmpid = 5;										 //
			strcpy_s(tmpimg, images[4].imgname);
			strcpy_s(images[4].imgname, images[5].imgname);
			strcpy_s(images[5].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 6 && changekey == true){
			tmpid = 7;										 //
			strcpy_s(tmpimg, images[6].imgname);
			strcpy_s(images[6].imgname, images[7].imgname);
			strcpy_s(images[7].imgname, tmpimg);
			changekey = false;
		}
		if (tmpid == 7 && changekey == true){
			tmpid = 8;										 //
			strcpy_s(tmpimg, images[7].imgname);
			strcpy_s(images[7].imgname, images[8].imgname);
			strcpy_s(images[8].imgname, tmpimg);
			changekey = false;
		}
	}
	
	//place your codes for other keys here
}
//
void imgcords()
{

	
	for (i = 0; i < 9; i++){
		strcpy_s(images[i].imgname, filename[randdata[i]]);
	}
	for (i = 0; i < 9; i++){
		//printf("%d-x=%d y=%d\n", i, images[i].x, images[i].y);
	}
	for (i = 0; i < 9; i++){
		if (strcmp(images[i].imgname, filename[2]) == 0){
			tmpid = i;
			break;
		}
	}
}
void sec()
{
	if (runtime == true){
		second++;
	}
	if (second % 60 == 0){
		minute++;
		second = 0;
	}
	
}
void nanoseconds()
{
	if (runtime == true){
		nanosec++;
	}
	if (nanosec > 99){
		nanosec = 0;
	}
}
void imgarrange()
{
	randdata[0] = rand() % 9;
	while (1){
		randdata[1] = rand() % 9;
		if (randdata[1] != randdata[0]){
			break;
		}
	}
	while (1){
		randdata[2] = rand() % 9;
		if (randdata[2] != randdata[0] && randdata[2] != randdata[1]){
			break;
		}
	}
	while (1){
		randdata[3] = rand() % 9;
		if (randdata[3] != randdata[0] && randdata[2] != randdata[1] && randdata[3] != randdata[2]){
			break;
		}
	}
	while (1){
		randdata[4] = rand() % 9;
		if (randdata[4] != randdata[0] && randdata[4] != randdata[1] && randdata[4] != randdata[2] && randdata[4] != randdata[3]){
			break;
		}
	}
	while (1){
		randdata[5] = rand() % 9;
		if (randdata[5] != randdata[0] && randdata[5] != randdata[1] && randdata[5] != randdata[2] && randdata[5] != randdata[3] && randdata[5] != randdata[4]){
			break;
		}
	}
	while (1){
		randdata[6] = rand() % 9;
		if (randdata[6] != randdata[0] && randdata[6] != randdata[1] && randdata[6] != randdata[2] && randdata[6] != randdata[3] && randdata[6] != randdata[4] && randdata[6] != randdata[5]){
			break;
		}
	}
	while (1){
		randdata[7] = rand() % 9;
		if (randdata[7] != randdata[0] && randdata[7] != randdata[1] && randdata[7] != randdata[2] && randdata[7] != randdata[3] && randdata[7] != randdata[4] && randdata[7] != randdata[5] && randdata[7] != randdata[6]){
			break;
		}
	}
	while (1){
		randdata[8] = rand() % 9;
		if (randdata[8] != randdata[0] && randdata[8] != randdata[1] && randdata[8] != randdata[2] && randdata[8] != randdata[3] && randdata[8] != randdata[4] && randdata[8] != randdata[5] && randdata[8] != randdata[6] && randdata[8] != randdata[7]){
			break;
		}
	}

}
int main()
{
	
	imgarrange();
	PlaySound(filename[10], NULL, SND_LOOP | SND_ASYNC);
	iSetTimer(10, nanoseconds);
	iSetTimer(1000, sec);
	//place your own initialization codes here.
	for (i = 0; i < 9; i++){
		if (i % 3 == 0){
			posx = 0;
		}
		images[i].x = posx;
		posx += 200;

	}

	for (i = 0; i < 9; i++){
		if (i % 3 == 0 && i != 0){
			posy += 200;
		}
		images[i].y = posy;

	}
	imgcords();

	iInitialize(600, 700, "PUZZLE");
	return 0;
}
