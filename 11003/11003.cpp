// 11003.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>

int main()
{
    int N, L;

    std::cin >> N >> L;

    std::deque<std::pair<int ,int>> Deque;

    for (int i = 1; i <= N; ++i)
    {
        int Numb = 0;
        int Start = i - L + 1 > 0 ? i - L + 1 : 0;

        std::cin >> Numb;
        
        while (!Deque.empty() && Deque.back().second > Numb)
            Deque.pop_back();

        Deque.push_back(std::make_pair(i, Numb));
        
        if (!Deque.empty() && Start - 1 >= Deque.front().first)
            Deque.pop_front();

        std::cout << Deque.front().second << " ";
    }

    return 0;
}