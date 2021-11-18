# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>
# include <conio.h>
# include <string.h>
void show(char str[][30], int n);
void update(char str[][30], int n);
int main(void)
{
	char s[30][30] =
	{
		"************",
		"*o         *",
		"* **********",
		"* *   *   **",
		"* * * * * **",
		"* * * * *  *",
		"* * * * *  *",
		"* * * * ** *",
		"* * * * ** *",
		"* * * * ** *",
		"*   *   **  ",
		"************"

	};

	int n = 12;
	show(s, n);
	update(s, n);

	return 0;
}

void show(char str[][30], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		puts(str[i]);
	}
}
void update(char str[][30], int n)
{
	int x = 1, y = 1; //¼ÇÂ¼³õÊ¼Î»ÖÃ
	int exit_x = 10, exit_y = 11;
	char input;
	while (x != exit_x || y != exit_y)
	{
		if (kbhit())
		{
			input = getch();
			if (input == 'w' && str[x - 1][y] != '*')
			{
				str[x][y] = ' ';
				x--;
				str[x][y] = 'o';
			}
			else if (input == 'a' && str[x][y - 1] != '*')
			{
				str[x][y] = ' ';
				y--;
				str[x][y] = 'o';
			}
			else if (input == 's' && str[x + 1][y] != '*')
			{
				str[x][y] = ' ';
				x++;
				str[x][y] = 'o';
			}
			else if (input == 'd' && str[x][y + 1] != '*')
			{
				str[x][y] = ' ';
				y++;
				str[x][y] = 'o';
			}
		}

		system("cls");
		show(str, n);
		Sleep(200);

	}

	printf("You Win!!!");
}
