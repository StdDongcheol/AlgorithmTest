// 14659.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::vector<int> vec;
    std::vector<int> vecResult;
    std::cin >> N;

    vec.resize(N + 1);
    vecResult.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        std::cin >> vec[i];

    int Best = 1;
    int index = 1;

    while (index < N)
    {
        int CurHeight = vec[Best];

        if (CurHeight - vec[index + 1] < 0)
            Best = index + 1;
        
        else
            ++vecResult[Best];

        ++index;
    }

    std::sort(vecResult.begin(), vecResult.end(), std::greater<int>());

    std::cout << vecResult[0];
}