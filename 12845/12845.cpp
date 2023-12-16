// 12845.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
    {
        std::cin >> vec[i];
    }
    
    std::sort(vec.begin(), vec.end());

    int Sum = 0;
    int Level = vec[N - 1];
    for (int i = N - 2; i >= 0; --i)
    {
         Sum += (Level + vec[i]);
    }

    std::cout << Sum;

    return 0;
}
