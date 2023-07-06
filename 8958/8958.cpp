#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {

        int score = 0;
        int CurScore = 0;
        std::string str;
        std::cin >> str;

        for (int j = 0; j < str.length(); ++j)
        {
            if (str[j] == 'O')
            {
                ++score;
                CurScore += score;
            }
            else
            {
                score = 0;
            }
        }
        std::cout << CurScore << '\n';
    }

    return 0;
}