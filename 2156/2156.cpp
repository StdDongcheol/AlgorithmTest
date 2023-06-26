// 2156.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[10001];
int dp[10001];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; ++i)
	{
		dp[i] = std::max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
		dp[i] = std::max(dp[i - 1], dp[i]);
	}

	std::cout << dp[N];
}