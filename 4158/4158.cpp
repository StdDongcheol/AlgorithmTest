// 4158.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> _vec1, std::vector<int> vec2)
{
    int Count = 0;

    for (int TargetNumb : _vec1)
    {
        int Start = 0;
        int End = vec2.size() - 1;
        int Middle = (Start + End) / 2;

        while (Start <= End)
        {
            Middle = (Start + End) / 2;

            if (vec2[Middle] <= TargetNumb)
            {
                Start = Middle + 1;
                if (vec2[Middle] == TargetNumb)
                {
                    ++Count;
                    break;
                }
            }
            else
            {
                End = Middle - 1;
            }
        }
    }

    return Count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    while(true)
    {
        int N, M;
        std::cin >> N >> M;
        
        if (N == 0 && M == 0)
            break;

        std::vector<int> vecN(N);
        std::vector<int> vecM(M);

        for (int i = 0; i < N; ++i)
            std::cin >> vecN[i];
        for (int i = 0; i < M; ++i)
            std::cin >> vecM[i];

        if (vecN.size() > vecM.size())
            std::cout << BinarySearch(vecN, vecM) << '\n';
        else
            std::cout << BinarySearch(vecM, vecN) << '\n';

    }

    return 0;
}