// 1916.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX 214748364

int Dist[1001];
bool Check[1001];
std::vector<std::vector<std::pair<int, int>>> vecMap;
int Start, Dest;

void Dijkstra(int _Start)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({ 0 , _Start});
    Dist[_Start] = 0;

    while (!q.empty())
    {
        int Cost = q.top().first;
        int CurDest = q.top().second;
        q.pop();

        if (Check[CurDest])
            continue;

        Check[CurDest] = true;

        for (int i = 0; i < vecMap[CurDest].size(); ++i)
        {
            int MoveDist = vecMap[CurDest][i].first;
            int MoveIndex = vecMap[CurDest][i].second;

            if (!Check[MoveIndex])
            {
                if (Cost + MoveDist < Dist[MoveIndex])
                {
                    Dist[MoveIndex] = Cost + MoveDist;
                    q.push({ Dist[MoveIndex], MoveIndex });
                }
            }
        }
    }

    std::cout << Dist[Dest];
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    vecMap.resize(1001);

    std::fill(Dist, Dist + 1001, INT_MAX);

    for (int i = 0; i < M; ++i)
    {
        int s, e, cost;
        std::cin >> s >> e >> cost;
        vecMap[s].push_back({cost,  e});
    }
    std::cin >> Start >> Dest;

    Dijkstra(Start);

    return 0;
}
