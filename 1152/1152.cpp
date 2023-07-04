#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::string str;
    std::getline(std::cin, str);

    bool WordCheck = false;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ' && !WordCheck)
        {
            WordCheck = true;
            ++N;
        }

        if (str[i] == ' ')
        {
            WordCheck = false;
        }
    }

    std::cout << N;
    return 0;
}
