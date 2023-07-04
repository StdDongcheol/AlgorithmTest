#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;

        int Count = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '(')
                ++Count;
            else if (str[i] == ')')
                --Count;

            if (Count < 0)
                break;
        }
        if (Count == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}