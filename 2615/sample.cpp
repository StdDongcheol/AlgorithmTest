
#include <iostream>
#define MAX 21
using namespace std;

bool ch[MAX][MAX] = { false, };
int arr[MAX][MAX], ny, nx, my[] = { -1,0,1,1 }, mx[] = { 1,1,1,0 };

void bf(int y, int x, int st_y, int st_x, int num, int dir)
{
    ch[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        ny = y + my[i];
        nx = x + mx[i];

        if (ny >= 1 && ny <= 19 && nx >= 1 && nx <= 19
            && !ch[ny][nx]
            && arr[y][x] == arr[ny][nx])
        {
            if (y == ny)
            { // 가로
                if (dir == 1)
                    bf(ny, nx, st_y, st_x, num + 1, dir);
                else
                    bf(ny, nx, y, x, 2, 1);
            }

            else if (x == nx)
            { // 세로
                if (dir == 2)
                    bf(ny, nx, st_y, st_x, num + 1, dir);

                else
                    bf(ny, nx, y, x, 2, 2);
            }

            else if (y - ny == 1 && nx - x == 1)
            { // 위 대각선
                if (dir == 3)
                    bf(ny, nx, st_y, st_x, num + 1, dir);
                else
                    bf(ny, nx, y, x, 2, 3);
            }

            else
            { //아래 대각선
                if (dir == 4)
                    bf(ny, nx, st_y, st_x, num + 1, dir);
                else
                    bf(ny, nx, y, x, 2, 4);
            }
        }
    }

    ch[y][x] = false;

    if (num == 5)
    {
        if (dir == 1)
        {
            if ((x > 5 && arr[y][x] == arr[y][x - 5]) ||
                (x < 19 && arr[y][x] == arr[y][x + 1]))
                return;
        }
        else if (dir == 2)
        {
            if ((y > 5 && arr[y][x] == arr[y - 5][x]) ||
                (y < 19 && arr[y][x] == arr[y + 1][x]))
                return;
        }
        else if (dir == 3)
        {
            if ((y < 15 && x>5 && arr[y][x] == arr[y + 5][x - 5]) ||
                (y > 1 && x < 19 && arr[y][x] == arr[y - 1][x + 1]))
                return;
        }
        else if (dir == 4)
        {
            if ((y > 5 && x > 5 && arr[y][x] == arr[y - 5][x - 5]) ||
                (y < 19 && x < 19 && arr[y][x] == arr[y + 1][x + 1]))
                return;
        }

        cout << arr[y][x] << "\n" << st_y << " " << st_x << "\n";

        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
            cin >> arr[i][j];
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if ((arr[i][j] == 1 || arr[i][j] == 2) && !ch[i][j])
                bf(i, j, i, j, 1, 0);
        }
    }

    cout << 0 << "\n";
    return 0;
}