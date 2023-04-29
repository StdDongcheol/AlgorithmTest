// 1715.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    int Sum = 0;
    int N;
    std::vector<int> vecNum;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pque;
    std::cin >> N;

    vecNum.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vecNum[i];
    }

    for (int i = 0; i < N; ++i)
    {
        pque.push(vecNum[i]);
    }

    while (pque.size() != 1)
    {
        int Data = pque.top();
        pque.pop();

        int Data2 = pque.top();
        pque.pop();

        Sum += (Data + Data2);
        pque.push(Data + Data2);
    }

    std::cout << Sum;
}
