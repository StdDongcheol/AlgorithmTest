// 1931.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N;
	std::vector<std::pair<int, int>> vec;
	
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int S, E;

		std::cin >> S >> E;
		vec.push_back(std::make_pair(E, S));
	}

	std::sort(vec.begin(), vec.end());

	int Count = 0;
	int End = -1;

	for (int i = 0; i < N; ++i)
	{
		if (vec[i].second >= End)
		{
			End = vec[i].first;
			++Count;
		}
	}

	std::cout << Count;
	return 0;
}
