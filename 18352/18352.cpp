

#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999

std::vector<int> vecDist;
std::vector<std::vector<int>> vecN;

int N, M, K, X;

int main()
{
    std::cin >> N >> M >> K >> X;

    vecN.resize(N + 1);
    vecDist.resize(N + 1, INF);

    for (int i = 0; i < M; ++i)
    {
        int U, V;
        std::cin >> U >> V;
        vecN[U].push_back(V);
    }

    std::queue<int> q;
    q.push(X);
    vecDist[X] = 0;

    while (!q.empty())
    {
        int Index = q.front();
        q.pop();

        for (int i = 0; i < vecN[Index].size(); ++i)
        {
            int NextIndex = vecN[Index][i];
            if (vecDist[NextIndex] == INF)
            {
                vecDist[NextIndex] = vecDist[Index] + 1;
                q.push(NextIndex);
            }
        }
    }

    bool check = false;
    for (int i = 1; i <= N; ++i)
    {
        if (vecDist[i] == K)
        {
            check = true;
            std::cout << i << '\n';
        }
    }

    if (!check)
        std::cout << -1;
    return 0;
}
