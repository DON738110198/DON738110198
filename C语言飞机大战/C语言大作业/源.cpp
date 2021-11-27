# include <stdio.h>
# include <stdlib.h>
# include <windows.h>
# include <conio.h>
int x, y, enemy_x, enemy_y, high, width;
int isfired, iskilled;
int bullet_x, bullet_y;
int score;
void show();
void start_up();
void update_without_input();
void update_with_input();
void gotoxy(int x, int y);
void HideCursor();
int main(void)
{
	start_up();

	while (1)
	{
		//显示飞机
		show();
		update_without_input();
		update_with_input();

	}


	return 0;
}



void start_up()
{
	high = 20;
	width = 30;
	x = high / 2;
	y = width / 2;
	bullet_y = y;
	bullet_x = -1;
	enemy_x = 0;
	enemy_y = width / 2;
	score = 0;
	void HideCursor();

}
void show()
{
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == x && y == j)
			{
				printf("*");
			}
			else if (i == bullet_x && j == bullet_y)
			{
				printf("|");
			}
			else if (i == enemy_x && j == enemy_y)
			{
				printf("@");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("得分：\n%d", score);
}
void update_without_input()
{
	if (bullet_x == enemy_x && bullet_y == enemy_y)
	{
		score++;
		// 生成新敌人
		enemy_x = 0;
		enemy_y = rand() % 20;
		bullet_x = -1; // 子弹收走 
	}
	static int speed = 0;
	if (speed < 30)
	{
		speed++;
	}
	if (bullet_x >= 0)
		bullet_x--;

	if (enemy_x < high)
	{
		if (speed == 30) // 每次循环都让speed++，当speed== 5时，才让这个敌人下降一次，这样子做用户的操作就不会被影响 
		{
			enemy_x++;
			speed = 0;
		}
	}
	else
	{
		enemy_y = rand() % 20;
		enemy_x = 0;
	}
	if (enemy_x == x && enemy_y == y)
	{
		system("cls");
		printf("你失败了\n你的分数是%d", score);
		exit(-1);
	}
}
void update_with_input()
{
	char input;
	if (kbhit())
	{
		input = getch();
		if (input == 'a')
			y--;
		if (input == 's')
			x++;
		if (input == 'd')
			y++;
		if (input == 'w')
			x--;
		if (input == ' ')
		{
			bullet_x = x - 1;
			bullet_y = y;
		}
	}

}
void gotoxy(int a, int b)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = a;
	pos.Y = b;
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
