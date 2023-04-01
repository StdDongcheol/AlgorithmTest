// 2751.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
std::vector<int> Arr;
std::vector<int> TempArr;

void Merge(int S, int E)
{
    if (E - S < 1)
    {
        return;
    }

    int Middle = S + (E - S) / 2;

    Merge(S, Middle);
    Merge(Middle + 1, E);

    int MergePoint = S;
    int L = S;
    int R = Middle + 1;

    for (int i = S; i <= E; ++i)
    {
        TempArr[i] = Arr[i];
    }

    while (L <= Middle && R <= E)
    {
        if (TempArr[L] < TempArr[R])
        {
            Arr[MergePoint] = TempArr[L];
            ++MergePoint;
            ++L;
        }

        else
        {
            Arr[MergePoint] = TempArr[R];
            MergePoint++;
            ++R;
        }
    }

    while (L <= Middle)
    {
        Arr[MergePoint] = TempArr[L];
        ++MergePoint;
        ++L;
    }
    while (R <= E)
    {
        Arr[MergePoint] = TempArr[R];
        ++MergePoint;
        ++R;
    }
}

int main()
{

    std::cin >> N;

    Arr.resize(N + 1, 0);
    TempArr.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i) 
    {
        std::cin >> Arr[i];
    }

    Merge(1, N);

    for (int i = 1; i <= N; ++i)
    {
        std::cout << Arr[i] << "\n";
    }

    return 0;
}
