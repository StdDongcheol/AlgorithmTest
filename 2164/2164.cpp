// 2164.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int main()
{
    int N;
    std::queue<int> queue;

    std::cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        queue.push(i);
    }
    
    while (queue.size() > 1)
    {
        //1. Pop
        queue.pop();

        // 2.1. Top
        int TopNum = queue.front();
        queue.pop();

        // 2.2. to end
        queue.push(TopNum);
    }
    
    std::cout << queue.front();

    return 0;
}
