// 13305.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> vecStation(N);
    std::vector<int> vecDist(N - 1);

    for (int i = 0; i < N - 1; ++i)
        std::cin >> vecDist[i];

    for (int i = 0; i < N; ++i)
        std::cin >> vecStation[i];
    
    long long MinGas = 2000000000;
    long long Value = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        long long Dist = vecDist[i];
        
        if (MinGas > vecStation[i])
        {
            MinGas = vecStation[i];
        }

        Value += (MinGas * Dist);
    }

    std::cout << Value;

    return 0;
}