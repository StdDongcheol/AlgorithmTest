// 1987.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int R, C;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool wordCheck[26];

char arrMap[20][20];
bool arrCheck[20][20];
int arrCount[20][20];

int DFS(int _x, int _y, int _Count)
{
	int CurX = _x, CurY = _y;

	for (int i = 0; i < 4; ++i)
	{
		int NextX = CurX + dx[i];
		int NextY = CurY + dy[i];

		if (0 <= NextX && NextX < C && 0 <= NextY && NextY < R)
		{
			char NextChar = arrMap[NextY][NextX];

			if (NextChar == 'M')
				int a = 0;
			if (arrCheck[NextY][NextX] == false && wordCheck[(int)(NextChar - 'A')] == false)
			{
				arrCheck[NextY][NextX] = true;
				wordCheck[(int)(NextChar - 'A')] = true;
				arrCount[CurY][CurX] = std::max(DFS(NextX, NextY, _Count + 1), arrCount[CurY][CurX]);
				wordCheck[(int)(NextChar - 'A')] = false;
				arrCheck[NextY][NextX] = false;
			}
		}
	}


	return _Count;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < C; ++j)
		{
			arrMap[i][j] = str[j];
		}
	}

	arrCount[0][0] = 1;
	wordCheck[(int)(arrMap[0][0] - 'A')] = true;
	DFS(0, 0, arrCount[0][0]);

	int MaxCount = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			MaxCount = std::max(MaxCount, arrCount[i][j]);
		}
	}

	std::cout << MaxCount;

	return 0;
}
