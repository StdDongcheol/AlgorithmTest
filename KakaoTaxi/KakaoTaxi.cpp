// KakaoTaxi.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

std::vector<std::vector<int>> vecFloyd;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 99999999;
    vecFloyd.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        vecFloyd[i].resize(n + 1, 99999999);
    }
    for (int i = 1; i < vecFloyd.size(); ++i)
    {
        vecFloyd[i][i] = 0;
    }

    for (int i = 0; i < fares.size(); ++i)
    {
        vector<int> vec = fares[i];
        int U = vec[0];
        int V = vec[1];
        int W = vec[2];

        vecFloyd[U][V] = W;
        vecFloyd[V][U] = W;
    }


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                vecFloyd[j][k] = std::min(vecFloyd[j][k], vecFloyd[j][i] + vecFloyd[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        answer = std::min(answer, vecFloyd[s][i] + vecFloyd[i][a] + vecFloyd[i][b]);
    }

    return answer;
}

int main()
{
    
    solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} });
}