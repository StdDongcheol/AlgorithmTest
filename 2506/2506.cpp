
#include <iostream>

int main()
{
    int N;
    bool Answer[100] = { 0 };

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> Answer[i];
    }

    bool Check = false;
    int Sum = 0;
    int Point = 1;
    for (int i = 0; i < N; ++i)
    {
        if (Answer[i])
        {
            if (!Check)
                Check = true;

            Sum += Point;
            ++Point;
        }

        else
        {
            Point = 1;
            Check = false;
        }
    }

    std::cout << Sum;

    return 0;
}