// 2644_0.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> vecNode;
std::vector<int> vecCheck;
int N, M, A1, A2;

int BFS(int _index)
{
	int Count = 0;
	std::queue<int> q;

	q.push(_index);
	vecCheck[_index] = 0;

	while (!q.empty())
	{
		int CurIndex = q.front();
		q.pop();

		for (int i = 0; i < vecNode[CurIndex].size(); ++i)
		{
			int NextNode = vecNode[CurIndex][i];

			if (vecCheck[NextNode] == -1)
			{
				{
					vecCheck[NextNode] = vecCheck[CurIndex] + 1;
					q.push(NextNode);

					if (NextNode == A2)
						return vecCheck[NextNode];
				}
			}
		}
	}

	return -1;
}

int main()
{
	std::cin >> N;
	std::cin >> A1 >> A2;
	std::cin >> M;

	vecNode.resize(N + 1);
	vecCheck.resize(N + 1, -1);

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		vecNode[u].push_back(v);
		vecNode[v].push_back(u);
	}

	std::cout << BFS(A1);

	return 0;
}
