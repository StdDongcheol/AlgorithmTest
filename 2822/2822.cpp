// 2822.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> vec(8);

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        vec[i].second = i + 1;
        std::cin >> vec[i].first;
    }
    
    std::sort(vec.rbegin(), vec.rend());
    
    int Sum = 0;
    std::vector<int> vecRank;
    for (size_t i = 0; i < 5; i++)
    {
        Sum += vec[i].first;
        vecRank.push_back(vec[i].second);
    }
    std::sort(vecRank.begin(), vecRank.end());
    
    std::cout << Sum << '\n';

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << vecRank[i] << " ";
    }
}
