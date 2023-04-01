#include <iostream>
#include <vector>

using namespace std;

void MySwap(vector<int>& A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(std::vector<int>& Arr, int Start, int End)
{
    if (Start + 1 == End)
    {
        if (Arr[Start] > Arr[End])
            MySwap(Arr, Start, End);
        return End;
    }
    // Pivot값을 적당한 한가운데를 선정.
    int PivotIndex = (Start + End) / 2;

    // StartIndex, EndIndex 증감의 편의성을 위해 
    // PivotIndex와 Start의 위치를 교체.
    // Arr[Start] : Pivot Value
    MySwap(Arr, PivotIndex, Start);

    int StartIndex = Start + 1;
    int EndIndex = End;

    while (StartIndex <= EndIndex)
    {
        while (EndIndex >= Start + 1 && Arr[EndIndex] > Arr[Start])
            --EndIndex;

        while (StartIndex <= End && Arr[StartIndex] < Arr[Start])
            ++StartIndex;

        if (StartIndex < EndIndex)
        {
            MySwap(Arr, StartIndex, EndIndex);
            ++StartIndex;
            --EndIndex;
        }

        else
            break;
    }


    MySwap(Arr, Start, EndIndex);

    // Swap하고난뒤 현재 StartIndex는 곧 전에 사용되던 Pivot값.
    // *** 해당 StartIndex Pivot값을 기준으로 좌측은 Pivot보다 낮은 값,
    // 우측은 Pivot보다 큰 값으로 정렬됨.

    // 정렬된 Pivot의 StartIndex를 반환.
    return EndIndex;
}

void QuickSort(std::vector<int>& Arr, int Start, int End, int K)
{
    int Pivot = Partition(Arr, Start, End);

    if (Pivot == K)
        return;
    else if (K < Pivot)
        QuickSort(Arr, Start, Pivot - 1, K);    // 좌측 정렬
    else
        QuickSort(Arr, Pivot + 1, End, K);     // 우측 정렬
}

int main()
{
    int N, K;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, N - 1, K - 1);

    std::cout << A[K - 1];

    return 0;
}