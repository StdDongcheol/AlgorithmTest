// 7568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	int arr[51] = {};
	std::vector<std::pair<int, int>> vec;

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int L, K;
		std::cin >> K >> L;
		vec.push_back({ K , L });
	}

	for (int i = 0; i < N; ++i)
	{
		int Count = 1;

		for (int j = 0; j < N; ++j)
		{
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
				++Count;
		}

		arr[i] = Count;
	}

	for (int i = 0; i < N; ++i)
		std::cout << arr[i] << "\n";

	return 0;
}
