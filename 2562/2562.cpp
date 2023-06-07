// 2562.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int Numb[10] = {};

int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		int N;
		std::cin >> N;
		Numb[i] = N;
	}
	int Max = *std::max_element(Numb + 1, Numb + 10);
	
	std::cout << Max << '\n';

	for (int i = 1; i <= 9; ++i)
	{
		if (Max == Numb[i])
			std::cout << i;
	}
}