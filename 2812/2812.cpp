// 2812.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

int main()
{
    int N, K;
    std::string str;
    std::cin >> N >> K;
    std::cin >> str;
    
    std::stack<int> stkStr;
    std::stack<int> stk;
   
    for(int i = str.length() - 1; i >= 0; --i)
    {
        stkStr.push((int)str[i] - '0');
    }

    while (K > 0 && !stkStr.empty())
    {
        int NextNumb = stkStr.top();
        stkStr.pop();

        if (stk.empty())
        {
            stk.push(NextNumb);
            continue;
        }

        else 
        {
            while(!stk.empty() && NextNumb > stk.top())
            {
                if (K <= 0)
                    break;

                stk.pop();
                --K;
            }
            
            stk.push(NextNumb);
        }
    }

    std::string NumbStr;
    while (!stk.empty())
    {
        int Numb = stk.top();
        stk.pop();
        NumbStr += std::to_string(Numb);
    }

    std::reverse(NumbStr.begin(), NumbStr.end());

    while (!stkStr.empty())
    {
        int Numb = stkStr.top();
        stkStr.pop();
        NumbStr += std::to_string(Numb);
    }

    if (K > 0)
    {
        while (K > 0)
        {
            NumbStr.pop_back();
            --K;
        }
    }

    std::cout << NumbStr;

    return 0;
}
