// 1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

std::vector<int> vecDFS;
std::vector<int> vecBFS;
std::vector<bool> vecCheck;
std::vector<std::vector<int>> vecNodes;

void DFS(int index)
{
	if (vecCheck[index])
		return;

	vecCheck[index] = true;
	vecDFS.push_back(index);

	for (int i = 0; i < vecNodes[index].size(); ++i)
		DFS(vecNodes[index][i]);

	return;
}

void BFS(int index)
{
	std::queue<int> que;
	que.push(index);

	vecCheck[index] = true;

	while (!que.empty())
	{
		int node = que.front();
		que.pop();

		vecBFS.push_back(node);

		for (int i = 0; i < vecNodes[node].size(); ++i)
		{
			int Numb = vecNodes[node][i];

			if (!vecCheck[Numb])
			{
				vecCheck[Numb] = true;
				que.push(Numb);
			}
		}
	}
}

int main()
{
	int N, M, V;

	std::cin >> N >> M >> V;

	vecNodes.resize(N + 1);
	vecCheck.resize(N + 1);


	for (int i = 0; i < M; ++i)
	{
		int u, v;

		std::cin >> u >> v;

		vecNodes[u].push_back(v);
		vecNodes[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		std::sort(vecNodes[i].begin(), vecNodes[i].end());
	}

	DFS(V);

	for (int i = 0; i < vecCheck.size(); ++i)
		vecCheck[i] = false;

	BFS(V);

	for (int i = 0; i < vecDFS.size(); ++i)
		std::cout << vecDFS[i] << " ";

	std::cout << "\n";

	for (int i = 0; i < vecBFS.size(); ++i)
		std::cout << vecBFS[i] << " ";

	return 0;
}