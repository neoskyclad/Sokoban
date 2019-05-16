#include<stdio.h>
#include <termios.h>

int getch(void)
{
	int ch;
	struct termios buf, save;

	tcgetattr(0,&save);
	buf = save;
	buf.c_lflag &= ~(ICANON|ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}

#define h 75 // h : 왼쪽
#define j 80 // j : 아래
#define k 72 // k : 위
#define l 77 // l : 오른쪽
void Player_Move_Action()
{
	char key;
	int x = 0;
	int y = 0;
	while(1)
	{
		if(key == -32)
		{
			key = getch();

			switch(key)
			{
			case h: //왼쪽
				x = 1;
				break;
			case j: //아래
				y = -1;
				break;
			case k: //위
				y = 1;
				break;
			case l: //오른쪽
				x = -1;
				break;	
			}
		}
	}
}

int main()
{
	Player_Move_Action();
	return 0;
}	
