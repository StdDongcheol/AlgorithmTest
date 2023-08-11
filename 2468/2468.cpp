// 2468.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>


int arr[100][100];
bool check[100][100];
int N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int _x, int _y, int _depth)
{
    int Count = 1;
    std::queue<std::pair<int, int>> q;

    check[_y][_x] = true;
    q.push({ _x, _y });

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextX < N && NextX >= 0 && NextY < N && NextY >= 0)
            {
                if (arr[NextY][NextX] > _depth && !check[NextY][NextX])
                {
                    check[NextY][NextX] = true;
                    q.push({ NextX, NextY });
                }
            }
        }
    }

    return Count;
}

int main()
{
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    int MaxValue = 1;

    for (int c = 1; c <= 100; ++c)
    {
        int CurSum = 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (arr[i][j] > c && !check[i][j])
                    CurSum += BFS(j, i, c);
            }
        }

        MaxValue = std::max(CurSum, MaxValue);
        std::fill(check[0], check[0] + 10000, false);
    }
    
    std::cout << MaxValue;

    return 0;
}
