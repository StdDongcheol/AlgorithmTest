#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    std::vector<int> Arr;

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    std::cin >> N;

    Arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> Arr[i];
    }

    std::sort(Arr.begin(), Arr.end());

    int Count = 0;

    for (int i = 0; i < N; ++i)
    {
        int Start = 0;
        int End = N - 1;

        while (Start < End)
        {
            int Sum = Arr[Start] + Arr[End];

            if (Sum == Arr[i])
            {
                if (Start == i)
                    ++Start;
                else if (End == i)
                    --End;
                else
                {
                    ++Count;
                    break;
                }
            }
            else if (Sum > Arr[i])
                --End;
            else if (Sum < Arr[i])
                ++Start;
        }
    }

    std::cout << Count << "\n";

    return 0;
}