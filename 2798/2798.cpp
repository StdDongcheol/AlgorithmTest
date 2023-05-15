// 2798.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Result;

int main()
{
    int N;
    int M;
    int Answer = 0;
    std::vector<int> vecCards;

    std::cin >> N >> M;

    vecCards.resize(N);

    for (int i = 0; i < N; ++i)
        std::cin >> vecCards[i];

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                int Sum = vecCards[i] + vecCards[j] + vecCards[k];

                if (Sum <= M && Sum > Answer)
                    Answer = Sum;
            }
        }
    }

    std::cout << Answer;
}
