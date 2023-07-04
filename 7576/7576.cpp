// 7576.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arrMap[1001][1001];
bool arrCheck[1001][1001];
std::queue<std::pair<int, int>> MainQueue;
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Day = 0;

void BFS(int _x, int _y)
{
    std::queue<std::pair<int, int>> q;
    arrCheck[_y][_x] = true;

    q.push({ _x, _y });

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        arrCheck[CurY][CurX] = true;

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextY <= M && NextY >= 1 && NextX <= N && NextX >= 1)
            {
                if (!arrCheck[NextY][NextX] && arrMap[NextY][NextX] == 0)
                {
                    MainQueue.push({NextX, NextY});
                    arrMap[NextY][NextX] = 1;
                }
            }
        }
    }
}

int main()
{
    std::cin >> N >> M;
    std::queue<std::pair<int, int>> NextVec;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            std::cin >> arrMap[i][j];
            if (arrMap[i][j] == 1)
                NextVec.push({ j, i });
        }
    }
    
    MainQueue = NextVec;
    bool DayStart = false;
    while (!MainQueue.empty())
    {
        std::queue<std::pair<int, int>> queue = MainQueue;
        MainQueue = std::queue<std::pair<int, int>>();
        if (DayStart)
            ++Day;
        while (!queue.empty())
        {
            if (!DayStart)
                DayStart = true;
            BFS(queue.front().first, queue.front().second);
            queue.pop();
        }
    }

    bool Check = false;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (arrMap[i][j] == 0)
            {
                Check = true;
                break;
            }
        }
    }

    if(Check)
        std::cout << -1;
    else
        std::cout << Day;
}
