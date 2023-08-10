// 1261.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

char arr[101][101];
int check[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

void BFS()
{
	std::queue<std::pair<int, int>> q;
	std::queue<std::pair<int, int>> qwall;
	q.push({ 0, 0 });
	check[0][0] = 0;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX <= N && NextX >= 0 && NextY <= M && NextY >= 0 && check[NextY][NextX] == -1)
			{
				// 벽이다.
				if (arr[NextY][NextX] == '1')
				{
					check[NextY][NextX] = check[CurY][CurX] + 1;
					
					qwall.push({ NextX , NextY });
				}

				// 빈공간이다
				else
				{
					check[NextY][NextX] = check[CurY][CurX];
					q.push({NextX , NextY});
				}
			}
		}

		if (q.empty())
		{
			q = qwall;
			while (!qwall.empty())
				qwall.pop();
		}
	}

	return;
}

int main()
{
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < N; ++j)
			arr[i][j] = str[j];
	}

	std::fill(check[0], check[0] + 10201, -1);

	N--;
	M--;
	BFS();

	std::cout << check[M][N];
}