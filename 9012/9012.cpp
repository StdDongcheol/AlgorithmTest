#include <iostream>
#include <string>
#include <stack>

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::stack<char> stk;
        std::stack<char> tmpStk;
        std::string str;
        std::cin >> str;

        int Count = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            stk.push(str[i]);
        }

        while (!stk.empty())
        {
            char c = stk.top();
            stk.pop();

            if (!tmpStk.empty() && tmpStk.top() == ')' && c == '(')
            {
                tmpStk.pop();
            }
            else
            {
                tmpStk.push(c);
            }
        }

        if(!tmpStk.empty())
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }

    return 0;
}