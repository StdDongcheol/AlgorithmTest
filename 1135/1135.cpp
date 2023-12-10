// 1135.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> vecTree;
int Count = 0;

int DFS(int _Index)
{
	int Count = 0;

	std::vector<int> vecSize;

	for (int i = 0; i < vecTree[_Index].size(); ++i)
	{
		int CurIndex = vecTree[_Index][i];
		int CurCount = DFS(CurIndex);
		vecSize.push_back(CurCount);
	}

	std::sort(vecSize.rbegin(), vecSize.rend());

	for (int i = 0; i < vecSize.size(); ++i)
	{
		Count = std::max(Count, vecSize[i] + i);
	}

	return Count + 1;
}

int main()
{
	int N;
	std::cin >> N;

	vecTree.resize(N + 1);

	for (int i = 0; i < N; ++i)
	{
		int Index;
		std::cin >> Index;
		
		if (Index == -1)
			continue;

		vecTree[Index].push_back(i);
	}

	std::cout << DFS(0) - 1;

	return 0;
}
