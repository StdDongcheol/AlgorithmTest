// 14501.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int day[16];
int pay[16];
int result[16];

int main()
{
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> day[i] >> pay[i];
    }

    for (int i = N; i >= 1; --i) 
    {
        if (i + day[i] > N + 1)
            result[i] = result[i + 1];
        else
            result[i] = std::max(result[i + 1], pay[i] + result[i + day[i]]);
    }

    std::cout << result[1];

    return 0;
}
