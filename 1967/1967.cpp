// 1967.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define NONE -1

std::vector<std::vector<std::pair<int, int>>> vecNodes(10001);
std::vector<bool> vecVisit;

int ResultWeight = 0;

void DFS(int _CurIndex, int _SumWeight)
{
	// vecNodes 사이즈가 1일경우, 나는 단말노드로 간주하겠다.

	if (vecNodes[_CurIndex].size() == 1)
	{
		ResultWeight = std::max(ResultWeight, _SumWeight);
		return;
	}

	for (int i = 0; i < vecNodes[_CurIndex].size(); ++i)
	{
		int NextIndex = vecNodes[_CurIndex][i].first;
		int NextWeight = vecNodes[_CurIndex][i].second;

		if (vecVisit[NextIndex] == false)
		{
			vecVisit[NextIndex] = true;
			DFS(NextIndex, _SumWeight + NextWeight);
			vecVisit[NextIndex] = false;
		}
	}

	return;
}

int main()
{
	int N;
	std::cin >> N;
	vecVisit.resize(N + 1);
	while (!std::cin.eof())
	{
		int U, V, W;

		std::cin >> U >> V >> W;
		if (std::cin.eof())
			break;
		vecNodes[U].push_back({V, W});
		vecNodes[V].push_back({U, W});
	}

	std::vector<int> vecTerminalNode;
	for (int i = 1; i <= N; ++i)
	{
		size_t Size = vecNodes[i].size();
		if (Size == 1)
		{
			vecTerminalNode.push_back(i);
		}
	}

	for (int i = 0; i < vecTerminalNode.size(); ++i)
	{
		int TerminalIndex = vecTerminalNode[i];
		vecVisit[TerminalIndex] = true;
		vecVisit[vecNodes[TerminalIndex][0].first] = true;
		DFS(vecNodes[TerminalIndex][0].first, vecNodes[TerminalIndex][0].second);
		vecVisit[vecNodes[TerminalIndex][0].first] = false;
		vecVisit[TerminalIndex] = false;
	}

	std::cout << ResultWeight;

	return 0;
}