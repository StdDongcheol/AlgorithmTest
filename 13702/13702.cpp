// 13702.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec;
	int N, K;
	std::cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		int Numb;
		std::cin >> Numb;
		vec.push_back(Numb);
	}
	std::sort(vec.begin(), vec.end());

	long long Start = 0, End = 2147483647;
	long long Max = 0;

	while (Start <= End)
	{
		long long Middle = (Start + End) / 2;
		int CurCount = 0;

		if (Middle > 0)
		{
			for (int i = 0; i < N; ++i)
			{
				CurCount += (vec[i] / Middle);
			}
		}

		if (K > CurCount)
		{
			End = Middle - 1;
		}
		else if (K <= CurCount)
		{
			Max = std::max(Max, Middle);
			Start = Middle + 1;
		}
	}

    std::cout << Max;

	return 0;
}