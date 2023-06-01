// 11651.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

struct compare
{
    bool operator()(std::pair<int, int>& l, std::pair<int, int>& r)
    {
        if (l.second == r.second)
            return l.first > r.first;
        else
            return l.second > r.second;
    }
};

int main()
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int X, Y;
        std::cin >> X >> Y;
        pq.push({ X, Y });
    }

    while (!pq.empty())
    {
        std::cout << pq.top().first << " " << pq.top().second << '\n';
        pq.pop();
    }
}