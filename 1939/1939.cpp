


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<std::vector<std::pair<int, int>>> vec;
std::vector<bool> vecCheck;
int Start, End;

bool BFS(int _Start, int _CurWeight)
{
    std::queue<std::pair<int, int>> q;

    vecCheck[_Start] = true;
    q.push({ _Start, _CurWeight });

    while (!q.empty())
    {
        int CurIsland = q.front().first;
        int CurIslandCost = q.front().second;
        q.pop();

        if (CurIsland == End)
            return true;

        for (int i = 0; i < vec[CurIsland].size(); ++i)
        {
            int NextIsland = vec[CurIsland][i].first;
            int NextIslandCost = vec[CurIsland][i].second;
            if (vecCheck[NextIsland] == false && NextIslandCost >= CurIslandCost)
            {
                vecCheck[NextIsland] = true;
                q.push({NextIsland, CurIslandCost});
            }
        }
    }

    return false;
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, MaxWeight;
    std::cin >> N >> M;
    
    vec.resize(N + 1);
    vecCheck.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int U, V, W;
        std::cin >> U >> V >> W;

        vec[U].push_back({ V, W });
        vec[V].push_back({ U, W });

        MaxWeight = std::max(MaxWeight, W);
    }

    // 중량을 이분탐색으로 정해서 BFS탐색시키는건 시간초과나지 않아?
    // 시간초과 나지 않으면 어째서???
    // 그렇게 이분탐색으로 중량을 맞춰나가는게 더 효율적이라고>?"
    std::cin >> Start >> End;
    vecCheck[Start] = true;

    int BinaryStart = 0;
    int BinaryEnd = MaxWeight;
    int SearchWeight = 0;

    while (BinaryStart <= BinaryEnd)
    {
        std::fill(vecCheck.begin(), vecCheck.end(), false);

        int Middle = (BinaryStart + BinaryEnd) / 2;

        if (BFS(Start, Middle))
        {
            SearchWeight = std::max(SearchWeight, Middle);
            BinaryStart = Middle + 1;
        }
        else
        {
            BinaryEnd = Middle - 1;
        }
    }

    std::cout << SearchWeight;
    
    return 0;
}
