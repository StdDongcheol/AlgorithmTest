// 5585.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[6] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	int Count = 0;

	int N;
	std::cin >> N;
	N = 1000 - N;

	for (int i = 0; i < 6; ++i)
	{
		while (true)
		{
			if (N >= arr[i])
			{
				N -= arr[i];
				Count++;
			}
			else 
				break;
		}
	}
	
	std::cout << Count;

	return 0;
}