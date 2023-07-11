// 1072.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	long long X, Y, Z, CurZ;
	std::cin >> X >> Y;

	Z = 100* Y / X;
	if (Z >= 99)
	{
		std::cout << -1;
		return 0;
	}

	long long Start = 0;
	long long End = X;

	while (Start <= End)
	{
		long long Middle = (Start + End) / 2;

		CurZ = 100 * (Y + Middle) / (X + Middle);
		
		if (Z >= CurZ)
			Start = Middle + 1;
		else if (Z < CurZ)
			End = Middle - 1;
	}

	std::cout << Start;
}
