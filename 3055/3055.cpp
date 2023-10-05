// 3055.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>

char map[50][50];
int arr[50][50];
int R, C;
int EndX, EndY;

std::queue<std::pair<int, int>> Waterq;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void WaterStart()
{
	std::queue<std::pair<int, int>> q;

	while (!Waterq.empty())
	{
		int CurX = Waterq.front().first;
		int CurY = Waterq.front().second;
		Waterq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = dx[i] + CurX;
			int NextY = dy[i] + CurY;

			if (NextX < C && NextX >= 0 && NextY < R && NextY >= 0)
			{
				if ((map[NextY][NextX] != '*') && (map[NextY][NextX] != 'D') && (map[NextY][NextX] != 'X'))
				{
					map[NextY][NextX] = '*';
					q.push({ NextX, NextY });
				}
			}
		}
	}

	while (!q.empty())
	{
		Waterq.push(q.front());
		q.pop();
	}
}

int BFS(int _x, int _y)
{
	std::queue<std::pair<int, int>> q;
	std::queue<std::pair<int, int>> Moveq;
	q.push({_x, _y});

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();
		
		if (CurX == EndX && CurY == EndY)
			return arr[CurY][CurX];

		if (map[CurY][CurX] != '*')
		{
			for (int i = 0; i < 4; ++i)
			{
				int NextX = dx[i] + CurX;
				int NextY = dy[i] + CurY;

				if (NextX < C && NextX >= 0 && NextY < R && NextY >= 0 && arr[NextY][NextX] == 0)
				{
					if ((map[NextY][NextX] != '*') && (map[NextY][NextX] != 'X'))
					{
						Moveq.push({ NextX, NextY });
						arr[NextY][NextX] = arr[CurY][CurX] + 1;
					}
				}
			}
		}

		if (q.empty())
		{
			while (!Moveq.empty())
			{
				q.push(Moveq.front());
				Moveq.pop();
			}

			WaterStart();
		}
	}

	return -1;
}

int main()
{
	std::cin >> R >> C;
	int StartX = 0, StartY = 0;

	for (int i = 0; i < R; ++i)
	{
		std::string str;

		std::cin >> str;
		for (int j = 0; j < C; ++j)
		{
			map[i][j] = str[j];
			if (str[j] == 'D')
			{
				EndX = j;
				EndY = i;
			}
			else if (str[j] == 'S')
			{
				StartX = j;
				StartY = i;
			}
			else if (str[j] == '*')
			{
				Waterq.push({j, i});
			}
		}
	}
	
	int result = BFS(StartX, StartY);

	if (result == -1)
		std::cout << "KAKTUS";
	else
		std::cout << result;

	return 0;
}
