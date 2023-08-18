


#include <iostream>
#include <vector>
#include <queue>

#define INF 999999

std::vector<std::vector<int>> vec;
int check[501];
int N, M;

int main()
{
    std::cin >> N >> M;
    vec.resize(N + 1);
    std::fill(check, check + 501, INF);

    for (int i = 0; i < M; ++i)
    {
        int U, V;
        std::cin >> U >> V;
        vec[U].push_back(V);
        vec[V].push_back(U);
    }

    std::queue<int> q;
    check[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int CurIndex = q.front();
        q.pop();

        for (int i = 0; i < vec[CurIndex].size(); ++i)
        {
            int NextIndex = vec[CurIndex][i];
            
            if (check[NextIndex] == INF)
            {
                check[NextIndex] = check[CurIndex] + 1;
                q.push(NextIndex);
            }
        }
    }

    int Count = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (check[i] <= 2)
            ++Count;
    }

    std::cout << Count;

    return 0;
}
