// 2583.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int arrBoard[101][101];
bool arrCheck[101][101];

int N, M, K;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int _X, int _Y)
{
	std::queue<std::pair<int, int>> q;
	int Count = 1;

	arrCheck[_X][_Y] = true;

	q.push({_X, _Y});

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX < N && NextX >= 0
				&& NextY < M && NextY >= 0)
			{
				if (arrBoard[NextX][NextY] == 0 && !arrCheck[NextX][NextY])
				{
					q.push({NextX, NextY});
					arrCheck[NextX][NextY] = true;
					++Count;
				}
			}
		}
	}

	return Count;
}

int main()
{
	std::cin >> N >> M >> K;
	std::vector<int> vecCount;
	for (int i = 0; i < K; ++i)
	{
		int x1, x2, y1, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; ++j)
		{
			for (int k = x1; k < x2; ++k)
			{
				arrBoard[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Count = 0;

			if (arrBoard[i][j] == 0 && !arrCheck[i][j])
				vecCount.push_back(BFS(i, j));
		}
	}

	std::sort(vecCount.begin(), vecCount.end());
	
	for (int i : vecCount)
		std::cout << i << " ";
	
	return 0;
}
