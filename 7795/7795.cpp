// 7795.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    int T, N, M;
    std::cin >> T;

    while (T--)
    {
        std::cin >> N >> M;
        std::vector<int> vecA(N);
        std::vector<int> vecB(M);
        
        for (int i = 0; i < N; ++i)
        {
            std::cin >> vecA[i];
        }
        for (int i = 0; i < M; ++i)
        {
            std::cin >> vecB[i];
        }

        std::sort(vecA.begin(), vecA.end());
        std::sort(vecB.begin(), vecB.end());

        int Count = 0;
        for (int i = 0; i < N; ++i)
        {
            int Start = 0;
            int End = M - 1;

            while (Start <= End)
            {
                int Middle = (Start + End) / 2;

                if (vecB[Middle] >= vecA[i])
                {
                    End = Middle - 1;
                }
                else
                {
                    Start = Middle + 1;
                }
            }
            Count += Start;
        }

        std::cout << Count << '\n';
    }

}
