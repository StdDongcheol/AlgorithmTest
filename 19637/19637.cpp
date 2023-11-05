// 19637.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

std::map<int, std::string> MyMap;
std::vector<std::pair<int, std::string>> vec;
std::vector<std::string> vecTitle;
std::vector<int> vecScore;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        int Power;
        std::cin >> str >> Power;
        auto iter = MyMap.find(Power);
        
        if (iter == MyMap.end())
        {
            //vecScore.push_back(Power);
            //vec.push_back({ Power, str });
            MyMap.insert({ Power, str });
        }
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < M; ++i)
    {
        int CharPower;
        std::cin >> CharPower;

        int Start = 0;
        int End = MyMap.size() - 1;
        int Middle = (Start + End) / 2;
        while (Start <= End)
        {
            Middle = (Start + End) / 2;
            if (CharPower <= MyMap[Middle][0])  // 적다
            {
                End = Middle - 1;
            }
            else
            {
                Start = Middle + 1;
            }
        }

        if (CharPower > MyMap[Middle][0])
            std::cout << MyMap[Middle + 1][1] << "\n";
        else
            std::cout << MyMap[Middle][1] << "\n";
    }
    
    return 0;
}

