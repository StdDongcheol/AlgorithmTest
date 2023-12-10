// 1937.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int N, MaxCount;

int arrMap[500][500];
int MoveMap[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int _x, int _y)
{
    if (MoveMap[_y][_x] != 0)
        return MoveMap[_y][_x];

    MoveMap[_y][_x] = 1;

    int CurX = _x;
    int CurY = _y;
    int CurTree = arrMap[CurY][CurX];

    for (int i = 0; i < 4; ++i)
    {
        int NextX = CurX + dx[i];
        int NextY = CurY + dy[i];

        if (0 <= NextX && NextX < N && 0 <= NextY && NextY < N)
        {
            int NextTree = arrMap[NextY][NextX];
            if (NextTree > CurTree)
            {
                MoveMap[CurY][CurX] = std::max(MoveMap[CurY][CurX], DFS(NextX, NextY) + 1);
            }
        }
    }

    return MoveMap[_y][_x];
}

int main()
{
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cin >> arrMap[i][j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; j++)
        {
            MaxCount = std::max(MaxCount, DFS(j, i));
        }
    }
    
    std::cout << MaxCount;
    return 0;
}