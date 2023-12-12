// 12018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int N, M;
    int Count = 0;
    std::cin >> N >> M;
    

    for (int i = 0; i < N; ++i)
    {
        if (M <= 0)
            break;
        std::vector<int> vec;
        int CurNumb, MaxNumb;
        std::cin >> CurNumb >> MaxNumb;

        for (int j = 0; j < CurNumb; ++j)
        {
            int MileNumb;
            std::cin >> MileNumb;
            vec.push_back(MileNumb);
        }

        std::sort(vec.begin(), vec.end());

        if (MaxNumb <= CurNumb)
            pq.push(vec[CurNumb - MaxNumb]);
        else
            pq.push(1);
    }

    while (!pq.empty())
    {
        if (M - pq.top() < 0)
            break;

        M -= pq.top();
        pq.pop();
        ++Count;
    }
    
    std::cout << Count;
    return 0;
}