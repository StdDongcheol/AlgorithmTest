// 6118.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE -1

int N, M;
std::vector<int> vecDist;

int main()
{
	std::cin >> N >> M;

	// 1-based index
	std::vector<std::vector<int>> vec(N + 1);
	vecDist.resize(N + 1, MAX_VALUE);
	vecDist[1] = 0;

	for (int i = 0; i < M; ++i)
	{
		int U, V;
		std::cin >> U >> V;

		vec[U].push_back(V);
		vec[V].push_back(U);
	}

	std::queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int CurIndex = q.front();
		q.pop();

		for (int i = 0; i < vec[CurIndex].size(); ++i)
		{
			int NextIndex = vec[CurIndex][i];
			
			if (vecDist[NextIndex] == MAX_VALUE)
			{
				vecDist[NextIndex] = vecDist[CurIndex] + 1;
				q.push(NextIndex);
			}
			else
				vecDist[NextIndex] = std::min(vecDist[CurIndex] + 1, vecDist[NextIndex]);

		}
	}

	int MaxDist = *std::max_element(vecDist.begin(), vecDist.end());
	int ShortIndex = -1;
	int IndexCount = 0;

	for (int i = 1; i < vecDist.size(); ++i)
	{
		if (MaxDist == vecDist[i] && vecDist[i] != MAX_VALUE)
		{
			if (ShortIndex == -1)
				ShortIndex = i;

			++IndexCount;
		}
	}

	std::cout << ShortIndex << ' ' << MaxDist << ' ' << IndexCount;

	return 0;
}