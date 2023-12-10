// 3079.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<unsigned long long> vecN(N);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> vecN[i];
	}

	std::sort(vecN.begin(), vecN.end());

	unsigned long long Start = 1;
	unsigned long long End = vecN.back() * M;
	unsigned long long Middle = 0;
	unsigned long long Time = vecN.back() * M;

	while (Start <= End)
	{
		unsigned long long  CurCount = 0;
		Middle = (Start + End) / 2;

		for (int i = 0; i < N; ++i)
			CurCount += (Middle / vecN[i]);

		if (CurCount < M)
		{
			Start = Middle + 1;
		}
		else if (CurCount >= M)
		{
			Time = Middle;
			End = Middle - 1;
		}
	}

	std::cout << Time;

	return 0;
}