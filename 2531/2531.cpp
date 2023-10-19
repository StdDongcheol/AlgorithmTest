// 2531.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <deque>

int sushi[3001];

int main()
{
    // d : 초밥가짓수, k: 연속접시수, c:쿠폰번호
    int N, d, k, c;
    std::queue<int> q;
    std::deque<int> dq;

    std::cin >> N >> d >> k >> c;
    for (int i = 0; i < N; ++i)
    {
        int Numb;
        std::cin >> Numb;
        q.push(Numb);
    }

    ++sushi[c];
    int MaxCount = 0;
    int CurCount = 1;
    for (int i = 0; i < k; ++i)
    {
        int CurSushi = q.front();
        q.pop();
        
        if (sushi[CurSushi] == 0)
        {
            ++CurCount;
        }
        ++sushi[CurSushi];
        dq.push_back(CurSushi);
    }

    MaxCount = CurCount;

    for (int i = 1; i < N; ++i)
    {
        if (q.empty())
            break;

        int FrontSushi = dq.front();
        dq.pop_front();
        --sushi[FrontSushi];
        if (sushi[FrontSushi] == 0)
            --CurCount;
        q.push(FrontSushi);

        int CurSushi = q.front();
        q.pop();
        if (sushi[CurSushi] == 0)
        {
            ++CurCount;
        }
        ++sushi[CurSushi];
        dq.push_back(CurSushi);
        MaxCount = std::max(MaxCount, CurCount);
    }

    std::cout << MaxCount;

    return 0;
}
