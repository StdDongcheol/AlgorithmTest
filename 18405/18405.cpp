// 18405.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

typedef std::pair<int, std::pair<int, int>> Data;

int arrN[200][200];
bool arrCheck[200][200];
int N, K, S, X, Y;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
std::priority_queue<Data, std::vector<Data>, std::greater<Data>> pq;

int BFS()
{
	int Count = 0;
	std::queue<Data> q;
	while (!pq.empty())
	{
		if (S == 0)
			break;

		while (!pq.empty())
		{
			int CurVirus = pq.top().first;
			int CurX = pq.top().second.first;
			int CurY = pq.top().second.second;
			pq.pop();

			arrCheck[CurY][CurX] = true;

			for (int i = 0; i < 4; ++i)
			{
				int NextX = CurX + dx[i];
				int NextY = CurY + dy[i];

				if (0 <= NextX && NextX < N && 0 <= NextY && NextY < N && 
					arrCheck[NextY][NextX] == false)
				{
					arrN[NextY][NextX] = CurVirus;
					arrCheck[NextY][NextX] = true;
					q.push({ CurVirus, {NextX, NextY} });
				}
			}
		}
		++Count;

		if (Count == S)
			break;

		while (!q.empty())
		{
			pq.push(q.front());
			q.pop();
		}
	}

	return arrN[X - 1][Y - 1];
}

int main()
{
	std::cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> arrN[i][j];
			if (arrN[i][j] > 0)
			{
				pq.push({ arrN[i][j] , {j, i} });
			}
		}
	}
	std::cin >> S >> X >> Y;

	std::cout << BFS();

	return 0;
}