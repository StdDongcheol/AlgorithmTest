// 11728.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> vecN(N);
    std::vector<int> vecM(M);

    for (int i = 0; i < N; ++i)
        std::cin >> vecN[i];

    for (int i = 0; i < M; ++i)
        std::cin >> vecM[i];

    int NIndex = 0;
    int MIndex = 0;
    std::vector<int> result;

    while (NIndex != N && MIndex != M)
    {
        int LowVal = std::min(vecN[NIndex], vecM[MIndex]);
        result.push_back(LowVal);

        if (LowVal == vecN[NIndex])
            ++NIndex;
        else
            ++MIndex;
    }

    if (NIndex == N)
    {
        while (MIndex != M)
        {
            result.push_back(vecM[MIndex]);
            ++MIndex;
        }
    }
    else
    {
        while (NIndex != N)
        {
            result.push_back(vecN[NIndex]);
            ++NIndex;
        }
    }

    for (int i : result)
        std::cout << i << ' ';

    return 0;
}
