#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    std::sort(times.begin(), times.end());

    long long Left = 1;
    long long Right = (long long)(times[times.size() - 1]) * n;

    // 기초 Left = 0; Right = 60
    // Mid = 30
    while (Left <= Right)
    {
        long long Mid = (Left + Right) / 2;
        long long Count = 0;


        for (int i = 0; i < times.size(); ++i)
        {
            Count += Mid / times[i];
        }

        // n명 다 채웠다면
        if (Count >= n)
        {
            answer = Mid;
            Right = Mid - 1;
        }

        // Count가 n명을 다 못채웠다면
        // Mid값 증가시켜서 Left를 갱신
        else
            Left = Mid + 1;

    }

    return answer;
}

int main()
{
    solution(100000, { 7, 10 });
}