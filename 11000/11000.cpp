

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N;

int main()
{
	std::cin >> N;
	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < N; ++i)
	{
		int S, T;
		std::cin >> S >> T;
		vec.push_back({ S, T });
	}

	std::sort(vec.begin(), vec.end());

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	pq.push(vec[0].second);

	for (int i = 1; i < N; ++i)
	{
		int CurEnd = pq.top();
		int NextStart = vec[i].first;

		if (CurEnd <= NextStart)
		{
			pq.pop();
		}

		pq.push(vec[i].second);
	}

	std::cout << pq.size();

	return 0;
}