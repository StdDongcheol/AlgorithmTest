// 11000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N;

int main()
{
	int CurCount = 1;
	std::cin >> N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
	std::vector<std::pair<int, int>> vec(N);
	
	for (int i = 0; i < N; ++i)
	{
		int S, T;
		std::cin >> S >> T;
		vec[i] = { S, T };
	}
	
	std::sort(vec.begin(), vec.end());

	pq1.push(vec[0].second);
	
	for (int i = 1; i < vec.size(); ++i)
	{
		int CurEnd = pq1.top();

		if (CurEnd <= vec[i].first)
		{
			pq1.pop();
		}

		pq1.push(vec[i].second);
	}
	
	std::cout << pq1.size();

	return 0;
}
