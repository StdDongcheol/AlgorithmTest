// 1094.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int X, Count = 0;
	int Length = 64;
	std::cin >> X;

	while (X > 0)
	{
		if (Length > X)
			Length >>= 1;

		else
		{
			X -= Length;
			++Count;
		}
	}

	std::cout << Count;
	
	return 0;
}
