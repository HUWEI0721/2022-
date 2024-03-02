/*2153393 软件 胡峻玮*/
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
#define MAX_X 26
#define MAX_Y 10
#define num 50
void set(char map[MAX_Y][MAX_X], int row, int line)
{
    srand((unsigned)time(NULL));
    int num_b = num;
    while (num_b)
    {
        int x = rand() % row;
        int y = rand() % line;
        if (map[x][y] != '*')//判断没有地雷
        {
            map[x][y] = '*';//布置地雷
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i >= 0 && i < MAX_Y && j >= 0 && j < MAX_X && map[i][j] != '*')
                    {
                        map[i][j]++;
                    }
                }
            }
            num_b--;
        }
    }
}
void print(char map[MAX_Y][MAX_X], int row, int line)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < line; j++)
            if(map[i][j]=='*')
                cout << map[i][j] << " ";
            else
                cout<<(int)map[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    char map[MAX_Y][MAX_X] = { '\0' };
    int row = MAX_Y;
    int line = MAX_X;
    set(map, row, line);
    print(map, row, line);
	return 0;
}