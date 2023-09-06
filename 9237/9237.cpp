// 9237.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int N;

int main()
{
    int Day = 0;
    std::cin >> N;

    vec.resize(N);

    for (int i = 0; i < N; i++) 
        std::cin >> vec[i];

    std::sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < N; ++i)
        Day = std::max(Day, vec[i] + i + 1);

    std::cout << Day + 1;
}
