// 1012.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;

std::vector<std::vector<bool>> vecCheck;
std::vector<std::vector<int>> vecFarm;

void BFS(int X, int Y)
{
    std::queue<std::pair<int, int>> Myqueue;
    Myqueue.push(std::make_pair(X, Y));

    vecCheck[X][Y] = true;

    while (!Myqueue.empty())
    {
        int CurX = Myqueue.front().first;
        int CurY = Myqueue.front().second;
        Myqueue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int MoveX = CurX + dx[i];
            int MoveY = CurY + dy[i];

            if (MoveX >= N || MoveX < 0 || MoveY >= M || MoveY < 0)
                continue;

            if (!vecCheck[MoveX][MoveY] && vecFarm[MoveX][MoveY] == 1)
            {
                vecCheck[MoveX][MoveY] = true;
                Myqueue.push(std::make_pair(MoveX, MoveY));
            }
        }
    }
}

void CaseInit()
{
    vecCheck.resize(50);
    vecFarm.resize(50);
    for (int i = 0; i < vecCheck.size(); ++i)
    {
        vecCheck[i].assign(vecCheck.size(), false);
        vecFarm[i].assign(vecFarm.size(), 0);
    }
}


int main()
{
    int CaseCount = 0;
    std::vector<int> vecCount;
    std::cin >> CaseCount;

    int Count = 0;
    int Worm = 0;
    while (Count < CaseCount)
    {
        CaseInit();
        Worm = 0; // 가로 세로
        std::cin >> M >> N >> K;

        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            std::cin >> X >> Y;
            vecFarm[Y][X] = 1;
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (!vecCheck[i][j] && vecFarm[i][j] == 1)
                {
                    BFS(i, j);
                    ++Worm;
                }
            }
        }

        vecCount.push_back(Worm);
        ++Count;
    }

    for (int i = 0; i < vecCount.size(); ++i)
        std::cout << vecCount[i] << "\n";

    return 0;
}