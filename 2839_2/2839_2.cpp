// 2839_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int dp[5001];
int N;

int main()
{
    std::fill(dp, dp + 5001, 99999999);
    std::cin >> N;
    
    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= N; ++i)
    {
        dp[i] = std::min(dp[i - 3], dp[i - 5]) + 1;
    }

    if(dp[N] >= 99999999)
        std::cout << -1;
    else
        std::cout << dp[N];
}
