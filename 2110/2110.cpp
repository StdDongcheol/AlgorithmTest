// 2110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int arrN[200000];

int main()
{
	int N, M;
	int MaxLength = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
		std::cin >> arrN[i];

	std::sort(arrN, arrN + N);

	int Start = 1;
	int End = arrN[N - 1] - arrN[0];
	
	while (Start <= End)
	{
		int Middle = (Start + End) / 2;
		int StartIdx = arrN[0];
		int Count = 1;

		for (int i = 1; i < N; ++i)
		{
			if (arrN[i] - StartIdx >= Middle)
			{
				StartIdx = arrN[i];
				++Count;
			}
		}

		if (Count >= M)
		{
			MaxLength = std::max(MaxLength, Middle);
			Start = Middle + 1;
		}

		else
			End = Middle - 1;
	}

	std::cout << MaxLength;

	return 0;
}