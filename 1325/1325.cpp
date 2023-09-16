// 1325.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, M;
std::vector<std::vector<int>> vecNode;
std::vector<int> vecCount;
std::vector<bool> vecCheck;

void BFS(int _Index)
{
    std::queue<int> q;

    vecCheck[_Index] = true;
    q.push(_Index);

    while (!q.empty())
    {
        int CurIndex = q.front();
        q.pop();

        for (int i = 0; i < vecNode[CurIndex].size(); ++i)
        {
            int NextNode = vecNode[CurIndex][i];
            if (vecCheck[NextNode] == false)
            {
                vecCheck[NextNode] = true;
                ++vecCount[NextNode];
                q.push(NextNode);
            }
        }
    }
    return;
}

int main()
{
    std::cin >> N >> M;
    vecNode.resize(N + 1);
    vecCount.resize(N + 1);
    vecCheck.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int U, V;
        std::cin >> U >> V;

        vecNode[U].push_back(V);
    }

    std::vector<int> vecLarge;

    for (int i = 0; i < N; ++i)
    {
        BFS(i + 1);

        std::fill(vecCheck.begin(), vecCheck.end(), false);
    }

    int maxValue = *std::max_element(vecCount.begin(), vecCount.end());

    for (int i = 0; i < vecCount.size(); ++i)
    {
        if (vecCount[i] == maxValue)
        {
            std::cout << i << " ";
        }
    }


    return 0;
}