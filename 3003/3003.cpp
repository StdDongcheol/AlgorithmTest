#include <iostream>

int main()
{
    int Arr[6] = { 0 };
    int Chess[6] = { 1, 1, 2, 2, 2, 8 };

    for (int i = 0; i < 6; ++i)
    {
        std::cin >> Arr[i];
        Arr[i] = Chess[i] - Arr[i];
    }
        
    for (int i = 0; i < 6; ++i)
    {
        std::cout << Arr[i];
    }


    return 0;
}