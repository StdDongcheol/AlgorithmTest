// NumberGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int IndexA = 0;
    int IndexB = 0;

    std::sort(A.rbegin(), A.rend());
    std::sort(B.rbegin(), B.rend());

    while (IndexA < A.size())
    {
        if (A[IndexA] < B[IndexB])
        {
            ++IndexB;
            ++answer;
        }

        ++IndexA;
    }

    return answer;
}

int main()
{
    solution({ 5, 1, 3, 7 }, { 2,2,6,8 });
    return 0;
}