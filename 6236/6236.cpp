// 6236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>

#define INT_M 2147483647

int main()
{
	int N, M;
	int Sum = 0;
	std::cin >> N >> M;
	std::vector<int> vec(N);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> vec[i];
		Sum += vec[i];
	}
	
	int Start = 1;
	int End = INT_M;
	int Middle = 0;

	while (Start <= End)
	{
		Middle = (Start + End) / 2;
		int CurMoney = Middle;
		int Count = 1;

		for (int i = 0; i < N; ++i)
		{
			if (CurMoney >= vec[i])
				CurMoney -= vec[i];
			else
			{
				CurMoney = Middle - vec[i];
				++Count;
			}
		}

		// 인출횟수가 많았다 == 한번에 인출하는 돈의 양이 부족했다
		// 따라서 인출금액을 늘린다
		if (Count > M)
		{
			Start = Middle + 1;
		}
		else
		{
			End = Middle - 1;
		}
	}

	std::cout << Middle;
	return 0;
}
