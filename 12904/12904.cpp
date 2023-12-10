// 12904.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

std::string S, T;

int main()
{
    std::cin >> S >> T;

    while (T.length() >= 1)
    {
        if (S == T)
        {
            std::cout << 1;
            return 0;
        }

        if (T.back() == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }

    std::cout << 0;

    return 0;
}
