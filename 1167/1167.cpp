// 1167.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> vecTree;
std::vector<int> vecCheck;
std::vector<bool> vecSearchCheck;
int Length = 0;


void BFS(int Index)
{
    std::queue<int> queue;

    queue.push(Index);
    while (!queue.empty())
    {
        int V = queue.front();
        queue.pop();
        vecSearchCheck[V] = true;

        bool Check = false;
        for (int i = 0; i < vecTree[V].size(); ++i)
        {
            if (vecTree[V][i] == -1)
                continue;

            // Cost
            int NextCost = vecTree[V][i];

            if (vecCheck[i] == 0 && !vecSearchCheck[i])
            {
                Check = true;
                vecCheck[i] = vecCheck[V] + NextCost;
                queue.push(i);
            }
        }

        // 단말노드.
        if (!Check)
        {
            if (Length < vecCheck[V])
                Length = vecCheck[V];
        }
    }

}


int main()
{
    int V;
    int u, v, cost;

    std::cin >> V;

    vecTree.resize(V + 1);
    vecCheck.resize(V + 1, 0);
    vecSearchCheck.resize(V + 1, 0);
    for (int i = 1; i <= V; ++i)
    {
        vecTree[i].resize(V + 1, -1);
    }

    for (int i = 1; i <= V; ++i)
    {
        std::cin >> u;
        while (true)
        {
            std::cin >> v;

            if (v == -1)
                break;
            
            std::cin >> cost;
            vecTree[u][v] = cost;
        }
    }

    BFS(1);

    std::cout << "Hello World!\n";
}