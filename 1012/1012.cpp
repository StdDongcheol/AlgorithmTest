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

bool BFS(int X, int Y)
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

    return vecCheck[X][Y];
}

void CaseInit()
{
    vecCheck.resize(25);
    for (int i = 0; i < vecCheck.size(); ++i)
    {
        vecCheck[i].resize(25, false);
    }

    vecFarm.resize(25);
    for (int i = 0; i < vecFarm.size(); ++i)
    {
        vecFarm[i].resize(25, 0);
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
        Worm = 0;
        std::cin >> N >> M >> K; 

        std::vector<std::pair<int, int>> vecCoord;
        
        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            std::cin >> X >> Y;
            vecCoord.push_back(std::make_pair(X, Y));
            vecFarm[Y][X] = 1;
        }

        for (int i = 0; i < vecCoord.size(); ++i)
        {
            if (!vecCheck[vecCoord[i].first][vecCoord[i].second])
            {
                BFS(vecCoord[i].first, vecCoord[i].second);
                ++Worm;
            }
        }

        vecCount.push_back(Worm);
        ++Count;
    }

    for(int i = 0; i < vecCount.size(); ++i)
        std::cout << vecCount[i] << "\n";

    return 0;
}