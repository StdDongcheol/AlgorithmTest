// 2606.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int Count = 0;

std::vector<bool> vecCheck;
std::vector<std::vector<int>> vecNode;

void DFS(int _Index)
{
    vecCheck[_Index] = true;

    for (int i = 0; i < vecNode[_Index].size(); ++i)
    {
        int NextIndex = vecNode[_Index][i];

        if (!vecCheck[NextIndex])
        {
            ++Count;
            DFS(NextIndex);
        }
    }
}

int main()
{
    int N;
    int PairN;

    std::cin >> N >> PairN;
    vecNode.resize(N + 1);
    vecCheck.resize(N + 1, false);

    for (int i = 0; i < PairN; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        vecNode[u].push_back(v);
        vecNode[v].push_back(u);
    }

    DFS(1);

    std::cout << Count;
}
