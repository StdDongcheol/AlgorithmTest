// 2343.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int arrN[100000];

int main()
{
    int N, M;
    std::cin >> N >> M;

    int Start = 0;
    int End = 0;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> arrN[i];
        End += arrN[i];
        if (Start < arrN[i])
            Start = arrN[i];
    }

    while (Start <= End)
    {
        int Middle = (Start + End) / 2;
        int Sum = 0;
        int Count = 0;

        for (int i = 0; i < N; ++i)
        {
            if (Middle < Sum + arrN[i])
            {
                ++Count;
                Sum = 0;
            }

            Sum += arrN[i];
        }

        if (Sum > 0)
            ++Count;

        // 음반 갯수가 많다 == 평균값이 너무 작다
        // 평균값 늘리기위한 End = middle -1;
        if (M < Count)
            Start = Middle + 1;

        // 평균값 줄이기위한 End = middle -1;
        else if (M >= Count)
            End = Middle - 1;
    }

    std::cout << Start;
}
