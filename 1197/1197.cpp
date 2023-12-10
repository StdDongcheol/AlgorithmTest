// 1197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int V, E;

std::vector<int> vecNodes;

int Find(int _Index)
{
	if (vecNodes[_Index] == _Index)
		return _Index;
	else
	{
		vecNodes[_Index] = Find(vecNodes[_Index]);
		return vecNodes[_Index];
	}
}

bool IsCycle(int _V1, int _V2)
{
	return (bool)(vecNodes[_V1] == vecNodes[_V2]);
}

// _End가 대표노드가 된다.
void MakeUnion(int _Start, int _End)
{
	int StartNode = Find(_Start);
	int EndNode = Find(_End);

	if (IsCycle(StartNode, EndNode))
		return;
	else
	{
		vecNodes[StartNode] = EndNode;
	}
}

int main()
{
	std::cin >> V >> E;
	vecNodes.resize(V + 1);

	for (size_t i = 1; i < vecNodes.size(); i++)
	{
		vecNodes[i] = i;
	}

	std::vector<std::pair<int, std::pair<int, int>>> vecEdge;

	for (int i = 0; i < E; ++i)
	{
		int U1, V1, W1;
		std::cin >> U1 >> V1 >> W1;
		vecEdge.push_back({ W1, {U1, V1} });
	}
	
	std::sort(vecEdge.begin(), vecEdge.end());

	int WeightSum = 0;

	for (int i = 0; i < vecEdge.size(); ++i)
	{
		int CurWeight = vecEdge[i].first;
		int StartV = vecEdge[i].second.first;
		int EndV = vecEdge[i].second.second;

		if (Find(StartV) == Find(EndV))
			continue;
		else
		{
			MakeUnion(StartV, EndV);
			WeightSum += CurWeight;
		}
	}
	
	std::cout << WeightSum;

}
