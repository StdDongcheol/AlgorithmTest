// 1158.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int main()
{
    std::deque<int> que;
    std::deque<int> answer;
    int N, K;

    std::cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        que.emplace_back(i);
    }

    while (!que.empty())
    {
        for (int Count = 1; Count < K; ++Count)
        {
            que.emplace_back(que.front());
            que.pop_front();
        }

        answer.emplace_back(que.front());
        que.pop_front();
    }

    std::cout << "<";
    while (!answer.empty())
    {
        std::cout << answer.front();
        answer.pop_front();

        if (answer.empty())
            std::cout << ">";
        else
            std::cout << ", ";

    }
    return 0;
}