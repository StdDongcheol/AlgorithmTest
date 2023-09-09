// 11060.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

#define INF_NUM 999999999
int arr[1001];
int dp[1001];
int N;

int main()
{
	std::cin >> N;
	std::fill(dp, dp + N + 1, INF_NUM);

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> arr[i];
	}

	dp[1] = 0;

	for (int i = 1; i < N; ++i)
	{
		int Cur = arr[i];

		for (int j = 1; j <= Cur; ++j)
		{
			if (dp[i] != INF_NUM)
				dp[j + i] = std::min(dp[j + i], dp[i] + 1);
		}
	}

	if (dp[N] == INF_NUM)
		std::cout << -1;
	else
		std::cout << dp[N];

	return 0;
}
