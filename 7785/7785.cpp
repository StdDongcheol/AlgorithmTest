// 7785.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main()
{
    int N;
    std::map<std::string, bool> MapLog;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string Name, State;
        std::cin >> Name >> State;

        if (State == "enter")
        {
            auto iter = MapLog.find(Name);
            if (MapLog.end() == iter)
            {
                MapLog.insert({ Name, true});
            }
            else
            {
                iter->second = true;
            }
        }
        else
        {
            MapLog.find(Name)->second = false;
        }
    }

    auto iter = MapLog.rbegin();
    auto iterEnd = MapLog.rend();
    for (; iter != iterEnd; ++iter)
    {
        if (iter->second == true)
            std::cout << iter->first << '\n';
    }
    
    return 0;
}
