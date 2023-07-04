// 1753.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INT_MAX       2147483647

using namespace std;

std::vector<std::vector<std::pair<int, int>>> vecMap;

int arrDist[20001];
bool arrCheck[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, StartIndex;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	std::cin >> V >> E;
	std::cin >> StartIndex;
	std::fill(arrDist, arrDist + 20001, INT_MAX);
	vecMap.resize(V + 1);

	arrDist[StartIndex] = 0;

	for (int i = 0; i < E; ++i)
	{
		int _u, _v, _w;

		std::cin >> _u >> _v >> _w;

		vecMap[_u].push_back(std::make_pair(_v, _w));
	}

	q.push({ arrDist[StartIndex], StartIndex });

	while (!q.empty())
	{
		int CurWeight = q.top().first;
		int CurIndex = q.top().second;
		q.pop();

		if (arrCheck[CurIndex])
			continue;

		arrCheck[StartIndex] = true;

		for (int i = 0; i < vecMap[CurIndex].size(); ++i)
		{
			int MoveIndex = vecMap[CurIndex][i].first;
			int MoveWeight = vecMap[CurIndex][i].second;

			if (CurWeight + MoveWeight < arrDist[MoveIndex])
			{
				arrDist[MoveIndex] = CurWeight + MoveWeight;
				q.push(std::make_pair(arrDist[MoveIndex], MoveIndex));
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		int D = arrDist[i];

		if (D == INT_MAX)
			std::cout << "INF" << "\n";

		else
			std::cout << D << "\n";
	}

	return 0;
}