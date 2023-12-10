// 1520.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arrMap[500][500];
int arrCheck[500][500];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DFS(int _x, int _y)
{
    if (_x == N - 1 && _y == M - 1)
        return 1;

    arrCheck[_y][_x] = 0;

    for (int i = 0; i < 4; ++i)
    {
        int NextX = _x + dx[i];
        int NextY = _y + dy[i];

        if (0 <= NextX && NextX < N && 0 <= NextY && NextY < M)
        {
            if (arrMap[NextY][NextX] < arrMap[_y][_x])
            {
                if (arrCheck[NextY][NextX] != -1)
                {
                    arrCheck[_y][_x] += arrCheck[NextY][NextX];
                }
                else
                {
                    arrCheck[_y][_x] += DFS(NextX, NextY);
                }
            }
        }
    }
    
    return arrCheck[_y][_x];
}

int main()
{

    std::cin >> M >> N;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> arrMap[i][j];
        }
    }
    std::fill(arrCheck[0], arrCheck[0] + 250000, -1);
    std::cout << DFS(0, 0);
    
    return 0;
}
