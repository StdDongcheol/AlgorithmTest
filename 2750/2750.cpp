// 2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int N;
	int Arr[1001] = { 0 };

	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> Arr[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N - i; ++j)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int Temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = Temp;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << Arr[i] << " ";
	}


	return 0;
}