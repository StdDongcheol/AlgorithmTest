
#include <iostream>

int main()
{
    int Number;
    int Score = 0;
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> Number;
        Score += Number;
    }

    std::cout << Score;

    return 0;
}