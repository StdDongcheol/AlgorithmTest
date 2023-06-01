// MostFarNode.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> vecNode;

int arrLength[20000] = { 99999, };
bool arrCheck[20000] = {};

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    std::queue<int> q;
    vecNode.resize(n + 1);
    std::fill(arrLength, arrLength + n + 1, 99999);

    for (int i = 0; i < edge.size(); ++i)
    {
        vecNode[edge[i][0]].push_back(edge[i][1]);
        vecNode[edge[i][1]].push_back(edge[i][0]);
    }

    q.push(1);

    arrLength[1] = 0;

    while (!q.empty())
    {
        int CurIndex = q.front();
        q.pop();

        for (int i = 0; i < vecNode[CurIndex].size(); ++i)
        {
            int Index = vecNode[CurIndex][i];
            if (!arrCheck[Index])
            {
                q.push(Index);
                arrLength[Index] = std::min(arrLength[Index], arrLength[CurIndex] + 1);
                arrCheck[Index] = true;
            }
        }
    }

    int MaxElement = *std::max_element(arrLength + 1, arrLength + n);

    for (int i = 1; i <= n; ++i)
    {
        if (MaxElement == arrLength[i])
            ++answer;
    }

    return answer;
}

int main()
{
    std::cout << solution(6, { {3, 6}, {4, 3 }, {3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });

}