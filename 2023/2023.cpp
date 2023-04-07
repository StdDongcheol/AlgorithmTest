// 2023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<int> Arr;
int N;

using namespace std;

bool IsPrimeNumber(int Number)
{
    int Count = Number / 2;

    for (int i = 2; i <= Count; ++i)
    {
        if (Number % i == 0)
            return false;
    }

    return true;
}

void DFS(int Number, int NCount)
{
    if (NCount == N)
    {
        if (IsPrimeNumber(Number))
            std::cout << Number << "\n";

        return;
    }

    for (int i = 1; i < 10; ++i)
    {
        if (i % 2 == 0)
            continue;

        if (IsPrimeNumber(Number))
            DFS(Number * 10 + i, NCount + 1);
    }
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}
