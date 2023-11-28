// 17070.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int N;
int map[16][16];

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int Count = 0;

// _Type: 0 -> 가로, 1 -> 세로, 2 -> 대각선, 
void DFS(int _x, int _y, int _Type)
{
	int CurX = _x;
	int CurY = _y;
	
	if (CurX == N - 1 && CurY == N - 1)
	{
		++Count;
		return; 
	}

	for (int i = 0; i < 3; ++i)
	{
		int NextX = CurX + dx[i];
		int NextY = CurY + dy[i];

		if (0 <= NextX && NextX < N && 0 <= NextY && NextY < N)
		{
			if (map[NextY][NextX] == 1)
				continue;

			if (i == 2)
			{
				if (map[NextY - 1][NextX] != 0 || map[NextY][NextX - 1] != 0)
					continue;
			}

			switch (_Type)
			{
			case 0:
				if (i != 1)
					DFS(NextX, NextY, i);
				break;
			case 1:
				if (i != 0)
					DFS(NextX, NextY, i);
				break;
			case 2:
				DFS(NextX, NextY, i);
				break;
			}
		}
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}

	DFS(1, 0, 0);
	std::cout << Count;

	return 0;
}
