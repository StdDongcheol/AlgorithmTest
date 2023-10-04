// 1946.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        int N;
        std::cin >> N;

        for(int i = 0; i < N; ++i)
        {
            int Paper, Commu;
            std::cin >> Paper >> Commu;
            pq.push({ Paper, Commu });
        }

        int Count = 0;
        int PaperCut = 99999999, CommuCut = 99999999;

        while (!pq.empty())
        {
            int CurPaper = pq.top().first;
            int CurCommu = pq.top().second;
            pq.pop();
            
            if (PaperCut < CurPaper)
            {
                if (CommuCut < CurCommu)
                {
                    continue;
                }
            }
            ++Count;
            PaperCut = std::min(CurPaper, PaperCut);
            CommuCut = std::min(CurCommu, CommuCut);
        }

        std::cout << Count << '\n';
    }

    return 0;
}
