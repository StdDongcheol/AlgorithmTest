// 7562.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[301][301];
bool check[301][301];

int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int BFS(int _x, int _y, int _endX, int _endY, int _I)
{
    std::queue<std::pair<int, int>> q;
    q.push({ _x, _y });
    check[_y][_x] = true;

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        if (CurX == _endX && CurY == _endY)
            break;

        for (int i = 0; i < 8; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextX < _I && NextX >= 0 && NextY < _I && NextY >= 0)
            {
                if (!check[NextY][NextX])
                {
                    check[NextY][NextX] = true;
                    arr[NextY][NextX] = arr[CurY][CurX] + 1;
                    q.push({ NextX, NextY });
                }
            }
        }
    }

    return arr[_endY][_endX];
}

int main()
{
    int T, I;

    std::cin >> T;

    while (T > 0)
    {
        int startX, startY, endX, endY;
        --T;
        std::cin >> I;
        std::cin >> startX >> startY;
        std::cin >> endX >> endY;

        std::cout << BFS(startX, startY, endX, endY, I) << std::endl;

        std::fill(arr[0], arr[0] + 90601, 0);
        std::fill(check[0], check[0] + 90601, false);
    }

}
