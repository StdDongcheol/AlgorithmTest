// 1463.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int dp[1000001];

int main()
{
    int N;
    std::cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0)
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        
        if (i % 3 == 0)
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
    }

    std::cout << dp[N];
}