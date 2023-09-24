// 17086.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

#define SHARK_POS -9999999

int N, M;
int arr[50][50];
bool check[50][50];

int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

void BFS(int _x, int _y)
{
	std::queue<std::pair<int, int>> q;
	q.push({ _x, _y });
	arr[_y][_x] = 0;
	check[_y][_x] = true;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX < M && NextX >= 0 && NextY < N && NextY >= 0 && check[NextY][NextX] == false && arr[NextY][NextX] != SHARK_POS)
			{
				check[NextY][NextX] = true;
				arr[NextY][NextX] = std::min(arr[NextY][NextX], arr[CurY][CurX] + 1);
				q.push({ NextX, NextY });
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
			if (arr[i][j] == 1)
				arr[i][j] = SHARK_POS;
			else
				arr[i][j] = 99999999;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (SHARK_POS == arr[i][j])
			{
				std::fill(check[0], check[0] + 2500, false);
				BFS(j, i);
			}
		}
	}

	int maxVal = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			maxVal = std::max(maxVal, arr[i][j]);
		}
	}

	std::cout << maxVal;
}
