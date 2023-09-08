// 1303.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>

char arr[100][100];
bool check[100][100];
int N, M;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int _x, int _y, char _c)
{
	int Count = 1;
	std::queue<std::pair<int, int>> q;
	
	check[_y][_x] = true;
	q.push({ _x, _y });

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX < N && NextX >= 0 && NextY < M && NextY >= 0)
			{
				if (check[NextY][NextX] == false && arr[NextY][NextX] == _c)
				{
					++Count;
					check[NextY][NextX] = true;
					q.push({ NextX, NextY });
				}
			}
		}
	}

	return Count * Count;
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < N; ++j)
		{
			arr[i][j] = str[j];
		}
	}

	int White = 0, Blue = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Count = 0;
			if (check[i][j] == false)
			{
				Count = BFS(j, i, arr[i][j]);

				if (arr[i][j] == 'W')
					White += Count;
				else if(arr[i][j] == 'B')
					Blue += Count;
			}
		}
	}

	std::cout << White << ' ' << Blue;

	return 0;
}