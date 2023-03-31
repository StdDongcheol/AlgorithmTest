// 11399.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int Arr[1001] = { 0 };
    int SumArr[1001] = { 0 };

    int N;

    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Arr[i];
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (Arr[j] < Arr[j - 1])
            {
                int Temp = Arr[j];
                Arr[j] = Arr[j - 1];
                Arr[j - 1] = Temp;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        SumArr[i] = SumArr[i - 1] + Arr[i];
    }
    
    int Sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        Sum += SumArr[i];
    }

    std::cout << Sum;

    return 0;
}