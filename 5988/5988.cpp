#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> vecStr;

    int N;
    std::cin >> N;
    vecStr.resize(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vecStr[i];

        int Number = (int)(vecStr[i][vecStr[i].length() - 1] - '0');

        if (Number % 2 == 0)
            std::cout << "even\n";
        else
            std::cout << "odd\n";
    }

    return 0;
}