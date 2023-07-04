// DoublePriorityQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    std::deque<int> dq;

    for (int i = 0; i < operations.size(); ++i)
    {
        std::string orderStr = operations[i];

        switch (orderStr[0])
        {
        case 'I':
        {
            int Numb = std::stoi(orderStr.substr(2));
            dq.push_back(Numb);
            std::sort(dq.begin(), dq.end(), std::greater<int>());
            break;
        }

        case 'D':
        {
            int Numb = std::stoi(orderStr.substr(2));

            if (!dq.empty())
            {
                if (Numb > 0)
                    dq.pop_front();

                else
                    dq.pop_back();
            }

            break;
        }
        }
    }

    if (dq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }
    return answer;
}

int main()
{
    solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });

    return 0;
}
