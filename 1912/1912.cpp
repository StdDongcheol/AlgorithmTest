// 1912.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[100001];
int dp[100001];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> arr[i];
	}

	int Max = -1000;
	for (int i = 1; i <= N; ++i)
	{
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
		if (Max < dp[i])
			Max = dp[i];
	}

	std::cout << Max;
}