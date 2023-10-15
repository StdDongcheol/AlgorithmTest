// 1110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int N, NextX, NextX2, NextNumb, Number;
	int Count = 0;
	std::cin >> N;
	Number = N;

	do
	{
		NextX2 = Number % 10; // 6
		Number /= 10;
		NextX = Number % 10; // 2

		NextNumb = NextX + NextX2;	// 8
		Number = NextX2 * 10 + ((NextX + NextX2) % 10);

		++Count;
	} while (Number != N);
	
	std::cout << Count;

	return 0;
}