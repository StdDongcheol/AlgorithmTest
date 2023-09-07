// 2636.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[100][100];
bool check[100][100];

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int _x, int _y)
{
	int Count = 0;
	std::queue<std::pair<int, int>> q;

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

			if (NextX < N && NextX >= 0 && NextY < M && NextY >= 0 && check[NextY][NextX] == false)
			{
				if (arr[NextY][NextX] == 1)
				{
					arr[NextY][NextX] = 0;
					check[NextY][NextX] = true;
					++Count;
				}
				else
				{
					q.push({ NextX, NextY });
					check[NextY][NextX] = true;
				}
			}
		}
	}

	return Count;
}

int main()
{
	std::cin >> M >> N;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int Time = 0;
	int Count = 0;

	while (true)
	{
		int CurCount = BFS(0, 0);
		
		if (CurCount <= 0)
			break;

		Count = CurCount;
		++Time;

		std::fill(check[0], check[0] + 10000, false);
	}

	std::cout << Time << '\n';
	std::cout << Count << '\n';
}
