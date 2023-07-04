// 1110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int N;
	int NextX;
	int NextX2;
	int Number;
	int Count = 0;
	std::cin >> N;
	Number = N;

	NextX = N % 10;	// 6
	N /= 10;
	NextX2 = N % 10;	// 2
	int NextX3 = NextX + NextX2;	// 2
	++Count;
	int newNumber = (NextX * 10) + NextX3;
	
	
	while (Number != newNumber)
	{
		NextX3 = NextX;
		NextX = newNumber % 10;	// 8
		newNumber /= 10;
		NextX2 = newNumber % 10;	// 6
		newNumber = NextX + NextX2;	// 6 + 8
		++Count;
	}

	std::cout << Count;

	return 0;
}