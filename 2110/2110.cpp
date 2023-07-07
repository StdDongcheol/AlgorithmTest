// 2110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int arrN[200000];

int main()
{
	int N = 0, M = 0;
	int Start = 0, End = 0;
	int MaxLength = 2000000000;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> arrN[i];
	}

	std::sort(arrN, arrN + N);
	
	Start = arrN[0];
	End = arrN[N - 1] - arrN[0];

	while (Start <= End)
	{
		int Middle = (Start + End) / 2;
		int StartVal = arrN[0];
		int Count = 1;

		for (int i = 1; i < N; ++i)
		{
			int Dist = arrN[i] - StartVal;
			if (Dist >= Middle)
			{
				StartVal = arrN[i];
				++Count;
			}
		}

		if (Count >= M)
		{
			MaxLength = std::max(MaxLength, Middle);
			Start = Middle + 1;
		}
		else if (Count < M)
		{
			End = Middle - 1;
		}
	}

	std::cout << MaxLength;
}