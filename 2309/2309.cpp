// 2309.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec;
    std::vector<int> vecAnswer;
    vec.resize(9);
    for (int i = 0; i < 9; ++i)
    {
        std::cin >> vec[i];
    }

    int sum = 0;
    do
    {
        sum = 0;

        for (int i = 0; i < 7; ++i)
        {
            sum += vec[i];
        }

        if (sum == 100)
            break;

    } while (std::next_permutation(vec.begin(), vec.end()));

    if (sum == 0)
        std::cout << 0 << "\n";

    else
    {
        for (int i = 0; i < 7; ++i)
            vecAnswer.push_back(vec[i]);

        std::sort(vecAnswer.begin(), vecAnswer.end());

        for (int i = 0; i < 7; ++i)
            std::cout << vecAnswer[i] << "\n";
    }


    return 0;
}
