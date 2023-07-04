// 9095.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[11];

int main()
{
	int T;
	std::cin >> T;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 7;

	for (int i = 5; i < 11; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int i = 0; i < T; ++i)
	{
		int N;
		std::cin >> N;

		std::cout << arr[N] << '\n';
	}
}
