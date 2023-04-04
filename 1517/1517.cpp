//

#include <iostream>
#include <vector>

std::vector<int> Data;
std::vector<int> TempData;
long SwapCount = 0;
using namespace std;

void MergeSorting(int S, int E)
{
    if (E - S < 1)
        return;

    int Middle = S + (E - S) / 2;

    MergeSorting(S, Middle);
    MergeSorting(Middle + 1, E);

    for (int i = S; i <= E; ++i)
    {
        TempData[i] = Data[i];
    }

    int TempIndex = S;
    int LIndex = S;
    int RIndex = Middle + 1;

    while (LIndex <= Middle && RIndex <= E)
    {
        if (TempData[LIndex] > TempData[RIndex])
        {
            Data[TempIndex] = TempData[RIndex];

            if ((Middle + 1) - LIndex > 0)
            {
                SwapCount += (Middle + 1) - LIndex;
            }

            ++RIndex;
            ++TempIndex;
        }

        else
        {
            Data[TempIndex] = TempData[LIndex];
            ++LIndex;
            ++TempIndex;
        }
    }

    while (LIndex <= Middle)
    {
        Data[TempIndex] = TempData[LIndex];
        ++LIndex;
        ++TempIndex;
    }

    while (RIndex <= E)
    {
        Data[TempIndex] = TempData[RIndex];
        ++RIndex;
        ++TempIndex;
    }
}

int main()
{
    int N;

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    std::cin >> N;

    Data.resize(N + 1, 0);
    TempData.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Data[i];
    }
    MergeSorting(1, N);
    std::cout << SwapCount;

    return 0;
}
