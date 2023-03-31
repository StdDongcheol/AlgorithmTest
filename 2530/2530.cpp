// 2530.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int A, B, C;
	int Timer;

	std::cin >> A >> B >> C;
	std::cin >> Timer;

	int Secs = Timer % 60;
	int Mins = Timer / 60;
	int Hour = Mins / 60;

	Timer -= Secs;
	Mins -= (Hour * 60);
	Hour %= 24;

	Secs += C;
	if (Secs >= 60)
	{
		Secs -= 60;
		++B;
	}	

	Mins += B;
	if (Mins >= 60)
	{
		Mins -= 60;
		++A;
	}

	Hour += A;
	if (Hour >= 24)
		Hour -= 24;
	
	std::cout << Hour << " " << Mins << " " << Secs;
		
	return 0;
}