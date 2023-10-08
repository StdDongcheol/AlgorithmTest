// 2212.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <deque>

int arr[10001];
int arrSum[10001];

int main()
{
    int N = 1, K = 0;
    std::cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int Numb;
        std::cin >> arr[i];
    }
    
    std::sort(arr, arr + N);
    
    int Dist = arr[N - 1] - arr[0];
    --K;

    for (int i = 1; i < N; ++i)
    {
        arrSum[i] = arr[i] - arr[i - 1];
    }

    while (K--)
    {
        int MaxIndex = 0, DistValue = 0;

        for (int i = 1; i < N; ++i)
        {
            DistValue = std::max(DistValue, arrSum[i]);

            if (DistValue == arrSum[i])
            {
                MaxIndex = i;
            }
        }

        if (arrSum[MaxIndex] == DistValue)
            arrSum[MaxIndex] = -1;

        Dist -= DistValue;
    }

    std::cout << Dist;

    return 0;
}
