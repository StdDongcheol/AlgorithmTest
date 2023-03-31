// 1253.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::vector<long long> Arr;
    std::vector<int> Asw;

    std::cin >> N;

    Arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> Arr[i];
    }

    std::sort(Arr.begin(), Arr.end());

    int Count = 0;

    for (int i = 0; i < N; ++i)
    {
        int Start = 0;
        int End = N - 1;

        while (Start < End)
        {
            long long Sum = Arr[Start] + Arr[End];

            if (Sum == Arr[i])
            {
                if (Start == i)
                    ++Start;

                else if (End == i)
                    --End;
                else
                {
                    ++Count;
                    break;
                }
            }

            else if (Sum > Arr[i])
                --End;
            else if (Sum < Arr[i])
                ++Start;
        }
    }

    std::cout << Count;
}
