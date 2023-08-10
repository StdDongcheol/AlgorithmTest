// 1748.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	int N;
	std::cin >> N;

	int Result = 1;
	int Adder = 1;
	int Divisor = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (i == Divisor * 10)
		{
			Divisor *= 10;
			++Adder;
		}

		Result += Adder;
	}

	std::cout << Result;
	return 0;
}
