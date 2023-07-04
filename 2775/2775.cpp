// 2775.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[15][15];

int main()
{
    int T;
    std::cin >> T;

    for (int i = 1; i <= 14; ++i)
        arr[0][i] = i;

    for (int a = 1; a <= 14; ++a)
    {
        for (int i = 1; i <= 14; ++i)
        {
            for (int j = 1; j <= i; ++j)
                arr[a][i] += arr[a - 1][j];
        }
    }

    for (int i = 0; i < T; ++i)
    {
        int k, n;
        std::cin >> k >> n;
        std::cout << arr[k][n] << '\n';
    }

    return 0;
}
