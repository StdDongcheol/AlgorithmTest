// 11724.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<bool> CheckArr;
std::vector<std::vector<int>> SearchArr;

using namespace std;

void DFS(int Index)
{
	if (CheckArr[Index])
		return;
	
	CheckArr[Index] = true;

	for (int i = 0; i < SearchArr[Index].size(); ++i)
	{
		if (CheckArr[SearchArr[Index][i]] == false)
		{
			DFS(SearchArr[Index][i]);
		} 
	}
}

int main()
{
	int N, M;

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	std::cin >> N >> M;
	CheckArr.resize(N + 1, false);
	SearchArr.resize(N + 1);


	for (int i = 1; i <= M; ++i)
	{
		int u, v;
		std::cin >> u >> v;

		SearchArr[u].push_back(v);
		SearchArr[v].push_back(u);
	}

	int Count = 0;
	
	for (int i = 1; i <= N; ++i)
	{
		if (CheckArr[i] == false)
			++Count;

		DFS(i);
	}

	std::cout << Count;

	return 0;
}
