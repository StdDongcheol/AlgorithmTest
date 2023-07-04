#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INT_MAX 2147483640

std::vector<std::vector<std::pair<int, int>>> vecMap;

int arrDist[100];
bool arrCheck[100];

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::fill(arrDist, arrDist + n, INT_MAX);
    vecMap.resize(n);
    std::vector<int> vecDist;

    for (int i = 0; i < costs.size(); ++i)
    {
        int U = costs[i][0];
        int V = costs[i][1];
        int W = costs[i][2];

        vecMap[U].push_back({ W, V });
        vecMap[V].push_back({ W, U });
    }

    for (int Count = 0; Count < n; ++Count)
    {
        arrDist[Count] = 0;
        pq.push({ arrDist[Count], Count });

        while (!pq.empty())
        {
            int CurWeight = pq.top().first;
            int CurIndex = pq.top().second;
            pq.pop();

            arrCheck[CurIndex] = true;

            for (int i = 0; i < vecMap[CurIndex].size(); ++i)
            {
                int NextWeight = vecMap[CurIndex][i].first;
                int NextIndex = vecMap[CurIndex][i].second;

                if (!arrCheck[NextIndex] && NextWeight < arrDist[NextIndex])
                {
                    arrDist[NextIndex] = NextWeight;
                    pq.push(std::make_pair(arrDist[NextIndex], NextIndex));
                }
            }
        }

        for (int i = 0; i < n; ++i)
            answer += arrDist[i];
        vecDist.push_back(answer);

        answer = 0;
        std::fill(arrDist, arrDist + n, INT_MAX);
        std::fill(arrCheck, arrCheck + n, false);
    }

    answer = *std::min_element(vecDist.begin(), vecDist.end());

    return answer;
}