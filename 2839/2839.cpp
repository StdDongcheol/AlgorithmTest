// 2839.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[5001] = {};

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i <= N; i++)
        arr[i] = 9999;

    arr[3] = 1;
    arr[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        arr[i] = std::min(arr[i - 3], arr[i - 5]) + 1;
    }

    if (arr[N] >= 9999)
    {
        std::cout << "-1";
    }
    else
        std::cout << arr[N];

}