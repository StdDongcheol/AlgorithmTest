// 10103.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int Score1 = 100, Score2 = 100;

	for (int i = 0; i < N; ++i)
	{
		int S1, S2;
		std::cin >> S1 >> S2;

		if (S1 > S2)
		{
			Score2 -= S1;
		}
		else if (S1 < S2)
		{
			Score1 -= S2;
		}
	}

	std::cout << Score1 << std::endl;
	std::cout << Score2 << std::endl;

	return 0;
}
