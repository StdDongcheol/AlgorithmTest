// 15904.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

char arrC[4] = {'U', 'C', 'P', 'C'};

int main()
{
    std::string str;
    std::getline(std::cin, str);
    
    int Count = 0;

    for (char c : str)
    {
        if (c == arrC[Count])
        {
            ++Count;
            if (Count >= 4)
            {
                std::cout << "I love UCPC";
                return 0;
            }
        }
    }
    
    std::cout << "I hate UCPC";

    return 0;
}
