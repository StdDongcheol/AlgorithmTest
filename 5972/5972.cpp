// 5972.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::vector<std::vector<std::pair<int, int>>> vecWay;
std::vector<int> vecDist;

void Find(int _index)
{
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	q.push({ 0, _index });
	vecDist[_index] = 0;

	while (!q.empty())
	{
		int CurWeight = q.top().first;
		int CurIndex = q.top().second;
		q.pop();

		for (int i = 0; i < vecWay[CurIndex].size(); ++i)
		{
			int NextIndex = vecWay[CurIndex][i].first;
			int NextWeigh = vecWay[CurIndex][i].second;

			if (vecDist[NextIndex] > vecDist[CurIndex] + NextWeigh)
			{
				vecDist[NextIndex] = vecDist[CurIndex] + NextWeigh;
				q.push({NextWeigh, NextIndex});
			}
		}
	}
}

int main()
{
	std::cin >> N >> M;
	vecWay.resize(N + 1);
	vecDist.resize(N + 1, 999999999);
	
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;

		std::cin >> u >> v >> w;
		vecWay[u].push_back({ v, w });
		vecWay[v].push_back({ u, w });
	}

	Find(1);

	std::cout << vecDist[N];

}
