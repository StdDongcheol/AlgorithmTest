// 11286.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <vector>

struct MyCompare
{
    bool operator()(int l, int r)
    {
        if (abs(l) == abs(r))
            return l > r;
        else
            return abs(l) > abs(r);
    }
};


int main()
{
    std::vector<int> answer;
    std::priority_queue<int, std::vector<int>, MyCompare> pQue;
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int Number;
        std::cin >> Number;

        if (Number != 0)
        {
            pQue.push(Number);
        }

        else
        {
            if (pQue.empty())
                answer.push_back(0);

            else
            {
                 answer.push_back(pQue.top());
                 pQue.pop();
            }
        }
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        std::cout << answer[i] << "\n";
    }
    
}