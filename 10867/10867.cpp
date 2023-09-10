// 10867.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i)
        std::cin >> vec[i];

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }


    return 0;
}