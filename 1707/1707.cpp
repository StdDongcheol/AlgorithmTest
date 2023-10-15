// 1707.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

bool CheckIt = true;

void DFS(std::vector<std::vector<int>>& _vecNode, std::vector<bool>& _vecCheck, int _CurIndex,
    std::vector<int>& _vecVisit)
{
    _vecCheck[_CurIndex] = true;
    
    for (int i = 0; i < _vecNode[_CurIndex].size(); ++i)
    {
        int NextNode = _vecNode[_CurIndex][i];

        if (_vecCheck[NextNode] == false)
        {
            _vecVisit[NextNode] = (_vecVisit[_CurIndex] + 1) % 2;

            DFS(_vecNode, _vecCheck, NextNode, _vecVisit);
        }
        else if (_vecVisit[_CurIndex] == _vecVisit[NextNode])
        {
            CheckIt = false;
            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int K;
    std::cin >> K;

    while (K > 0)
    {
        int V, E;
        std::cin >> V >> E;

        std::vector<std::vector<int>> vec(V + 1);
        std::vector<bool> vecCheck(V + 1);
        CheckIt = true;

        for (int i = 0; i < E; ++i)
        {
            int _u, _v;
            std::cin >> _u >> _v;

            vec[_u].push_back(_v);
            vec[_v].push_back(_u);
        }

        std::vector<int> vecVisit(V + 1);
        for (int i = 1; i <= V; ++i)
        {   
            if (CheckIt)
                DFS(vec, vecCheck, i, vecVisit);
            else
            {
                std::cout << "NO\n";
                break;
            }
        }

        if (CheckIt)
            std::cout << "YES\n";

        --K;
    }

    return 0;
}