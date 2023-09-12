// 9372.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int BFS(std::vector<std::vector<int>> _vec, std::vector<bool> _vecCheck, int _N)
{
	int Count = 0;
	std::queue<int> q;

	q.push(1);
	_vecCheck[1] = true;

	while (!q.empty())
	{
		int CurNode = q.front(); 
		q.pop();

		for (int i = 0; i < _vec[CurNode].size(); ++i)
		{
			int NextNode = _vec[CurNode][i];

			if (_vecCheck[NextNode] == false)
			{
				q.push(NextNode);
				_vecCheck[NextNode] = true;
				++Count;
			}
		}
	}

	return Count;
}

int main()
{
	int T;

	std::cin >> T;

	while(T > 0)
	{
		int Count = 0;
		int N, M;
		std::cin >> N >> M;

		std::vector<std::vector<int>> vec(N + 1);
		std::vector<bool> vecCheck(N + 1);

		for (int i = 0; i < M; ++i)
		{
			int U, V;
			std::cin >> U >> V;

			vec[U].push_back(V);
			vec[V].push_back(U);
		}

		std::cout << BFS(vec, vecCheck, N) << '\n';

		--T;
	}

	return 0;
}
