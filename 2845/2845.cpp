
#include <iostream>

int main()
{
    int L, P;
    int Article[5] = { 0 };

    std::cin >> L >> P;

    for (int i = 0; i < 5; ++i)
    {
        std::cin >> Article[i];
    }

    int Players = L * P;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << Article[i] - Players << " ";
    }

    return 0;
}