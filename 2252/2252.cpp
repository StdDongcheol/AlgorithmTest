// 2252.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int N, M;
	std::vector<std::vector<int>> vecNode;
	std::vector<int> vecInsert;
	std::queue<int> queue;

	std::cin >> N >> M;
	vecNode.resize(N + 1);
	vecInsert.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int A, B;

		std::cin >> A >> B;
		vecNode[A].push_back(B);
		++vecInsert[B];
	}

	for (int i = 1; i < vecInsert.size(); ++i)
	{
		if (vecInsert[i] == 0)
			queue.push(i);
	}

	while (!queue.empty())
	{
		int Index = queue.front();
		queue.pop();
		
		for (int i = 0; i < vecNode[Index].size(); ++i)
		{
			int NearNode = vecNode[Index][i];
			--vecInsert[NearNode];

			if (vecInsert[NearNode] == 0)
				queue.push(NearNode);
		}

		std::cout << Index << " ";
	}


	return 0;
}