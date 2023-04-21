// 2178.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> m_vecPath;
std::vector<std::vector<bool>> m_vecCheck;
int x[4] = { 1, 0, -1, 0 };
int y[4] = { 0, 1, 0, -1 };
int N, M;
int MoveCount = 0;

int BFS(int StartX, int StartY)
{
    std::queue<std::pair<int, int>> Que;
    Que.push(std::make_pair(StartX, StartY));

    while (!Que.empty())
    {
        int CurX = Que.front().first;
        int CurY = Que.front().second;
        Que.pop();

        m_vecCheck[CurX][CurY] = true;
        
        if (CurX == N && CurY == M)
        {
            return m_vecPath[CurX][CurY];
        }

        bool Check = false;

        for (int i = 0; i < 4; ++i)
        {
            int MoveX = CurX + x[i];
            int MoveY = CurY + y[i];

            if ((MoveX > N || MoveX <= 0) ||
                (MoveY > M || MoveY <= 0))
                continue;

            if (m_vecPath[MoveX][MoveY] == 1)
            {
                if (!m_vecCheck[MoveX][MoveY])
                {
                    Check = true;
                    m_vecPath[MoveX][MoveY] += m_vecPath[CurX][CurY];
                    Que.push(std::make_pair(MoveX, MoveY));
                }
            }
        }
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    m_vecPath.resize(N + 1);
    m_vecCheck.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        m_vecPath[i].resize(M + 1);
        m_vecCheck[i].resize(M + 1);
    }

    std::string Line;

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Line;
        for (int j = 1; j <= M; ++j)
        {
            m_vecPath[i][j] = static_cast<int>(Line[j - 1] - '0');
        }
    }

    std::cout << BFS(1, 1);

    return 0;
}