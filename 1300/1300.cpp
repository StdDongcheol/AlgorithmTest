// 1300.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long N, k;
	std::cin >> N >> k;

	long Start = 1;
	long End = k;
	long result = 0;
	while (Start <= End)
	{
		long Middle = (Start + End) / 2;

		long Sum = 0;
		for (long i = 1; i <= N; ++i)
		{
			long Count = (Middle / i) > N ? N : Middle / i;
			Sum += Count;
		}

		if (Sum < k)
		{
			Start = Middle + 1;
		}
		else if (Sum >= k)
		{
			End = Middle - 1;
			result = Middle;
		}
	}

	std::cout << result;

	return 0;
}

