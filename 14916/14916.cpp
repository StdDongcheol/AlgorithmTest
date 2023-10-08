// 14916.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int arr[100001];

int main()
{
    int N;
    std::cin >> N;
    std::fill(arr, arr + N + 1, -1);
    
    arr[2] = 1;
    arr[5] = 1;

    for (int i = 4; i <= N; ++i)
    {
        if (arr[i - 2] != -1)
        {
            arr[i] = arr[i - 2] + 1;
        }
        if (i >= 5 && arr[i - 5] != -1)
        {
            arr[i] = std::min(arr[i - 5] + 1, arr[i]);
        }
    }

    std::cout << arr[N];

    return 0;
}
