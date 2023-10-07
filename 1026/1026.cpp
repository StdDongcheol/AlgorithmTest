// 1026.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int N;

int main()
{
    std::cin >> N;

    std::vector<int> arrA(N);
    std::vector<int> arrB(N);

    for (int i = 0; i < N; ++i)
        std::cin >> arrA[i];

    for (int i = 0; i < N; ++i)
        std::cin >> arrB[i];

    std::sort(arrA.begin(), arrA.end());
    std::sort(arrB.rbegin(), arrB.rend());

    int Sum = 0;
    for (int i = 0; i < N; ++i)
    {
        Sum += (arrA[i] * arrB[i]);
    }

    std::cout << Sum << '\n';

    return 0;
}
