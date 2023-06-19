// 1003.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

unsigned long long arr[41][2];

int main()
{
    int T;
    std::cin >> T;

    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    arr[2][0] = 1;
    arr[2][1] = 1;

    for (int i = 3; i <= 40; ++i)
    {
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
    }

    for (int i = 0; i < T; ++i)
    {
        int N;
        std::cin >> N;

        std::cout << arr[N][0] << " " << arr[N][1] << '\n';
    }

    return 0;
}