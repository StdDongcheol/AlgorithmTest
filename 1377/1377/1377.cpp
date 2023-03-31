// 1377.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<std::pair<int, int>> A;
    std::vector<int> B;
    std::vector<int> C;

    int N;

    std::cin >> N;
 
    A.resize(N + 1);
    B.resize(N + 1);
    C.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> A[i].first;
        A[i].second = i;
    }
    
    std::sort(A.begin(), A.end());

    int MaxIndex = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (MaxIndex < A[i].second - i)
            MaxIndex = A[i].second - i;
    }

    std::cout << MaxIndex + 1;
}