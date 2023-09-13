// 11725.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> vec(N + 1);
	std::vector<int> vecNode(N + 1, -1);

	for (int i = 0; i < N - 1; ++i)
	{
		int U, V;

		std::cin >> U >> V;

		vec[U].push_back(V);
		vec[V].push_back(U);
	}

	std::queue<int> q;
	vecNode[1] = 0;
	q.push(1);
	
	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();

		for (int i = 0; i < vec[CurNode].size(); ++i)
		{
			int NextNode = vec[CurNode][i];

			if (vecNode[NextNode] == -1)
			{
				// CurNode를 부모노드로 설정.
				vecNode[NextNode] = CurNode;
				q.push(NextNode);
			}
		}
	}

	for (int i = 2; i < vecNode.size(); ++i)
		std::cout << vecNode[i] << '\n';

	return 0;
}