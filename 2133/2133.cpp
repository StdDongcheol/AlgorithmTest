// 2133.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[31];

int main()
{
    int N;
    std::cin >> N;

    arr[1] = 0;
    arr[2] = 3;
    arr[3] = 0;
    arr[4] = 11;

    for (int i = 6; i <= N; i += 2)
    {
        arr[i] = (arr[i - 4] * 3) + (arr[i - 2] * 2);
    }


    std::cout << arr[N];

    return 0;
}