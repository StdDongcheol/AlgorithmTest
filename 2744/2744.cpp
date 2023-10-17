#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        int Curchar = (int)str[i];
        if (Curchar >= 97)
        {
            std::cout << (char)toupper(Curchar);
        }
        else
        {
            std::cout << (char)tolower(Curchar);
        }
    }

    return 0;
}