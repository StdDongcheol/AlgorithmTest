// 4375.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int N;

	while (std::cin >> N)
	{
		int Numb = 0;
		int Count = 0;

		while (true)
		{
			Count++;
			Numb = (Numb * 10 + 1) % N;
			if (Numb == 0)
				break;
		}

		std::cout << Count << '\n';
	}
	return 0;
}
