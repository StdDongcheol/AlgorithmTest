// 11048.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int map[1000][1000];
int dp[1000][1000];
bool check[1000][1000];
int N, M;

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

int DFS(int _x, int _y)
{
    int CurX = _x;
    int CurY = _y;

    if (CurX == M - 1 && CurY == N - 1)
        return map[CurY][CurX];
    
    for (int i = 0; i < 3; ++i)
    {
        int NextX = CurX + dx[i];
        int NextY = CurY + dy[i];

        if (0 <= NextX && NextX < M && 0 <= NextY && NextY < N)
        {
            if (dp[NextY][NextX] == -1)
            {
                dp[CurY][CurX] = std::max(dp[CurY][CurX], map[CurY][CurX] + DFS(NextX, NextY));
            }
            else
                dp[CurY][CurX] = std::max(dp[CurY][CurX], map[CurY][CurX] + dp[NextY][NextX]);
        }
    }

    return dp[CurY][CurX];
}

int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> map[i][j];
        }
    }

    std::fill(dp[0], dp[0] + 1000000, -1);
    dp[0][0] = map[0][0];
    check[0][0] = true;
    DFS(0, 0);

    std::cout << dp[0][0];

    return 0;
}
