// 3109.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int dx[3] = { 1, 1, 1 };
int dy[3] = { -1, 0, 1 };
char map[10000][500];
bool check[10000][500];
int R, C;

bool DFS(int _x, int _y)
{
	check[_y][_x] = true;
	
	if (_x == C - 1)
	{
		return true;
	}

	for (int i = 0; i < 3; ++i)
	{
		int NextX = _x + dx[i];
		int NextY = _y + dy[i];

		if (0 <= NextY && NextY < R && 0 <= NextX && NextX < C)
		{
			if (check[NextY][NextX] == false && map[NextY][NextX] != 'x')
			{
				if (DFS(NextX, NextY))
					return true;
			}
		}
	}

	return false;
}

int main()
{
	std::cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			map[i][j] = str[j];
		}
	}

	int Count = 0;
	for (int i = 0; i < R; i++)
	{
		if (DFS(0, i))
		{
			++Count;
		}
	}

	std::cout << Count;

	return 0;
}
