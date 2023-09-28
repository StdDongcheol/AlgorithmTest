// 17266.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int N, M;
std::vector<int> vecPos;

bool CheckPos(int Length)
{
    if (vecPos[0] > Length)
        return false;

    for (int i = 0; i < vecPos.size() - 1; ++i)
    {
        if (vecPos[i + 1] - vecPos[i] > Length * 2)
            return false;
    }

    if (N - vecPos[M - 1] > Length)
        return false;

    return true;
}

int main()
{
    std::cin >> N >> M;
    vecPos.resize(M);

    for (int i = 0; i < M; ++i)
        std::cin >> vecPos[i];

    int Start = 0;
    int End = 100000;
    int Length = 999999999;

    while (Start <= End)
    {
        int Middle = (Start + End) / 2;

        if (CheckPos(Middle) == false)
        {
            Start = Middle + 1;
        }
        else
        {
            Length =  std::min(Middle, Length);
            End = Middle - 1;
        }
    }

    std::cout << Length;
}
