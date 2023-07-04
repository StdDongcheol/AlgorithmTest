// 1316.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

bool Check[26] = {};

int main()
{
    int N;
    std::cin >> N;

    int Count = 0;
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;
        bool IsGroup = true;
        for (int j = 0; j < str.length(); ++j)
        {
            int idx = (int)str[j] - 97;
            if (Check[idx] && str[j - 1] != str[j])
            {
                IsGroup = false;
                break;
            }
            else
                Check[idx] = true;
        }
        if (IsGroup)
            ++Count;

        std::fill(Check, Check + 26, false);
    }

    std::cout << Count;
    return 0;
}
