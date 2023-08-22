// 13565.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>

int arr[1000][1000];
bool check[1000][1000];
int M, N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int _x, int _y)
{
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

			if (NextX >= 0 && NextX < N && NextY >= 0 && NextY < M && !check[NextY][NextX] && arr[NextY][NextX] == 0)
			{
				check[NextY][NextX] = true;
				q.push({ NextX, NextY });
			}
		}
	}
}

int main()
{
	std::cin >> M >> N;

	for (int i = 0; i < M; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < N; ++j)
		{
			if(str[j] == '0')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (!check[0][i] && arr[0][i] == 0)
		{
			BFS(i, 0);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (check[M - 1][i])
		{
			std::cout << "YES";
			return 0;
		}	
	}

	std::cout << "NO";

	return 0;
}
