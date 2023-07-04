// RunAndJump.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

int dp[2000] = {};

long long solution(int n)
{
    long long answer = 0;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;

    return dp[n];
}