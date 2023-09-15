// 1068.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> vec;
std::vector<bool> vecCheck;

int RootNumb = -1;

int BFS(int _Index)
{
	int Count = 0;
	std::queue<int> q;
	q.push(_Index);

	vecCheck[_Index] = true;

	while (!q.empty())
	{
		int CurIndex = q.front();	
		q.pop();

		if (vec[CurIndex].size() == 1)
			++Count;
		else
		{
			for (int i = 0; i < vec[CurIndex].size(); ++i)
			{
				int NextIndex = vec[CurIndex][i];

				if (vecCheck[NextIndex] == false)
				{
					vecCheck[NextIndex] = true;
					q.push(vec[CurIndex][i]);
				}
			}
		}
	}

	return Count;
}

int main()
{
	int N;
	
	std::cin >> N;
	vec.resize(N);
	vecCheck.resize(N);


	for (int i = 0; i < N; ++i)
	{
		int Parent;
		std::cin >> Parent;

		if (Parent == -1)
			RootNumb = i;
		else
		{
			vec[i].push_back(Parent);
			vec[Parent].push_back(i);
		}
	}
	
	int DeleteNode;
	std::cin >> DeleteNode;

	for (int i = 0; i < vec[DeleteNode].size(); ++i)
	{
		int NearNode = vec[DeleteNode][i];

		if (NearNode == RootNumb)
			continue;

		auto iter = std::find(vec[NearNode].begin(), vec[NearNode].end(), DeleteNode);
		vec[NearNode].erase(iter);

	}
	vec[DeleteNode].clear();

	std::cout << BFS(RootNumb);

}
