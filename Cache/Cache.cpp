
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    std::deque<std::string> dq;

    int Count = 0;
    while (Count < cities.size())
    {
        std::string str = cities[Count];
        std::string LowerStr = "";

        for (auto i : str)
        {
            char alpha = static_cast<char>(tolower(i));
            LowerStr += alpha;
        }

        if (cacheSize != 0)
        {
            auto iter = std::find(dq.begin(), dq.end(), LowerStr);

            if (iter == dq.end())
            {
                if (dq.size() >= cacheSize)
                    dq.pop_front();

                dq.push_back(LowerStr);
                answer += 5;
            }

            else
            {
                dq.erase(iter);
                dq.push_back(LowerStr);
                answer += 1;
            }
        }

        else
            answer += 5;

        ++Count;
    }

    return answer;
}