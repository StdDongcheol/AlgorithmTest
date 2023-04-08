// 1032.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N;
    std::vector<std::string> vecStrings;
    std::vector<bool> vecCheck;
    std::cin >> N;
    
    vecStrings.resize(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vecStrings[i];
    }

    vecCheck.resize(vecStrings[0].size(), true);

    for (int i = 0; i < vecStrings[0].size(); ++i)
    {
        char CharTemp = vecStrings[0][i];

        for (int j = 1; j < vecStrings.size(); ++j)
        {
            char NewChar = vecStrings[j][i];

            if (CharTemp != NewChar)
            {
                vecCheck[i] = false;    
                break;
            }

            CharTemp = NewChar;
        }
    }

    for (int i = 0; i < vecStrings[0].size(); ++i)
    {
        if (vecCheck[i] == false)
            std::cout << "?";
        else
            std::cout << vecStrings[0][i];
    }

    return 0;
}