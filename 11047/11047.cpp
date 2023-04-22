// 11047.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N, K;
    int Count = 0;
    std::vector<int> vecCoins;
    std::cin >> N >> K;

    vecCoins.resize(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> vecCoins[i];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        if (K <= 0)
            break;

        if (vecCoins[i] / K <= 0)
            continue;

        int Coins = (vecCoins[i] / K);
        Count += Coins;
        K -= (Coins * vecCoins[i]);
    }

    std::cout << Count;

    return 0;
}