// 14940.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[1000][1000];
bool check[1000][1000];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int _x, int _y)
{
	std::queue<std::pair<int, int>> q;

	check[_y][_x] = true;
	q.push({ _x, _y });

	if (arr[_y][_x] == 2)
		arr[_y][_x] = 0;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX < M && NextX >= 0 && NextY < N && NextY >= 0)
			{
				if (!check[NextY][NextX] && arr[NextY][NextX] == 1)
				{
					arr[NextY][NextX] = arr[CurY][CurX] + 1;
					check[NextY][NextX] = true;
					q.push({NextX, NextY});
				}
			}
		}
	}
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 2 && !check[i][j])
				BFS(j, i);
			else if(arr[i][j] == 0)
				check[i][j] = true;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!check[i][j])
				std::cout << -1 << ' ';
			else
				std::cout << arr[i][j] << ' ';
		}

		std::cout << '\n';
	}
}