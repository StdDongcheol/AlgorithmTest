// 2792.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arrM[300000];

int main()
{
	int N, M;
	int Start = 1, End = 0;
	int Jewel = 1000000000;
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		std::cin >> arrM[i];
		End = std::max(End, arrM[i]);
	}
	
	while (Start <= End)
	{
		int Middle = (Start + End) / 2;
		int Count = 0;

		for (int i = 0; i < M; ++i)
		{
			Count += (arrM[i] / Middle);

			if (arrM[i] % Middle > 0)
				++Count;
		}

		if (Count > N)
			Start = Middle + 1;

		else if (Count <= N)
		{
			Jewel = std::min(Middle, Jewel);
			End = Middle - 1;
		}
	}

	std::cout << Jewel;

	return 0;
}
