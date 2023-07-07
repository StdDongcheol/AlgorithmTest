// 2776.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int arrN[1000000];
int arrM[1000000];

int main()
{
    int T, N, M;

    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        std::cin >> N;
        for (int j = 0; j < N; ++j)
            std::cin >> arrN[j];

        std::cin >> M;
        for (int j = 0; j < M; ++j)
            std::cin >> arrM[j];

        std::sort(arrN, arrN + N);

        for (int j = 0; j < M; ++j)
        {
            int Start = 0;
            int End = N - 1;

            bool Check = false;
            while (Start <= End)
            {
                int Middle = (Start + End) / 2;

                if (arrM[j] == arrN[Middle])
                {
                    std::cout << 1 << '\n';
                    Check = true;
                    break;
                }
                else if (arrM[j] < arrN[Middle])
                {
                    End = Middle - 1;
                }
                else if (arrM[j] > arrN[Middle])
                {
                    Start = Middle + 1;
                }
            }

            if (!Check)
                std::cout << 0 << '\n';
        }
    }
}