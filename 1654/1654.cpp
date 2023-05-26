// 1654.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, K;
	long long CurLength = 0;
	std::vector<int> vecLength;
	std::vector<int> vecK;

	std::cin >> N >> K;

	vecLength.resize(N);

	for (int i = 0; i < N; ++i)
		std::cin >> vecLength[i];

	long long Start = 1;
	long long End = *std::max_element(vecLength.begin(), vecLength.end());
	long long Middle = 0;

	while (Start <= End)
	{
		Middle = (Start + End) / 2;
		int Count = 0;

		for (int i = 0; i < N; ++i)
			Count += (vecLength[i] / Middle);

		if (Count >= K)
		{
			if (CurLength < Middle)
				CurLength = Middle;
			Start = Middle + 1;
		}

		else if (Count < K)
		{
			End = Middle - 1;
		}
	}

	std::cout << CurLength;

	return 0;
}