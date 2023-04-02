#include <iostream>

int main()
{
    long long A, B;

    std::cin >> A >> B;

    if (A > B)
    {
        unsigned long long Temp = A;
        A = B;
        B = Temp;
    }

    int Size = B - A - 1;

    if (Size <= 1)
        std::cout << "0";

    else
    {
        std::cout << Size << "\n";

        for (int i = 1; i <= Size; ++i)
        {
            std::cout << (unsigned long long)A + i << " ";
        }
    }

    return 0;
}