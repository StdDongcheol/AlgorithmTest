// 11727.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

long long arr[1001];

int main()
{
	int N;
	std::cin >> N;
	
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= N; ++i)
	{
		arr[i] = ((arr[i - 2] * 2) + arr[i - 1]) % 10007;
	}

	std::cout << arr[N];

	return 0;
}
