// 2467.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
	int N;
	std::vector<int> vec;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int numb;
		std::cin >> numb;
		vec.push_back(numb);
	}

	int Start = 0;
	int End = N - 1;
	int Liq1, Liq2, CurVal = 2100000000;

	while (Start < End)
	{
		int Sum = vec[Start] + vec[End];

		if (abs(Sum) < abs(CurVal))
		{
			CurVal = Sum;
			Liq1 = vec[Start];
			Liq2 = vec[End];
		}

		if (Sum > 0)
		{
			--End;
		}
		else if (Sum <= 0)
		{
			++Start;
		}
	}

	std::cout << std::min(Liq1, Liq2) << " " << std::max(Liq1, Liq2);
}
