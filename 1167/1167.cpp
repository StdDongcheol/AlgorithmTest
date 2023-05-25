// 1167.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<std::pair<int, int>>> vecTree;
std::vector<int> vecLength;
std::vector<bool> vecCheck;
int Length = 0;

void DFS(int _V, int _value)
{
    vecCheck[_V] = true;
    
    for (int i = 0; i < vecTree[_V].size(); ++i)
    {
        int NextV = vecTree[_V][i].first;

        if (vecCheck[NextV])
            continue;

        _value += vecTree[_V][i].second;
        vecLength[NextV]
        DFS(NextV, _value);

        _value -= vecTree[_V][i].second;
    }

    if (_value > Length)
        Length = _value;

    vecCheck[_V] = false;

    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int V;
    int u, v, cost;

    std::cin >> V;

    vecTree.resize(V + 1);
    vecLength.resize(V + 1, 0);
    vecCheck.resize(V + 1, 0);

    for (int i = 1; i <= V; ++i)
    {
        std::cin >> u;
        while (true)
        {
            std::cin >> v;

            if (v == -1)
                break;
            
            std::cin >> cost;
            vecTree[u].push_back(std::make_pair(v, cost));
        }
    }

    DFS(1, 0);

    std::cout << Length;
}