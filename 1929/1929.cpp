#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N, M;
    std::vector<bool> vecPrime;
    std::cin >> N >> M;

    vecPrime.resize(M + 1, true);

    for (int i = 2; i <= sqrt(M); ++i)
    {
        if (!vecPrime[i])
            continue;

        for (int j = i + i; j <= M; j += i)
        {
            vecPrime[j] = false;
        }
    }

    for (int i = N; i <= M; ++i)
    {
        if (vecPrime[i])
            std::cout << i << "\n";
    }

    return 0;
}