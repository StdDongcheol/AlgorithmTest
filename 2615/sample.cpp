
#include <iostream>

using namespace std;

bool Check[20][20] = { false };
int board[20][20] = {};
int MoveY, MoveX;
int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1, -1,  1 };

void bf(int y, int x, int st_y, int st_x, int num, int dir)
{
    Check[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        MoveY = y + dy[i];
        MoveX = x + dx[i];

        if (MoveY >= 1 && MoveY <= 19 && MoveX >= 1 && MoveX <= 19
            && !Check[MoveY][MoveX]
            && board[y][x] == board[MoveY][MoveX])
        {
            if (y == MoveY)
            { // 가로
                if (dir == 1)
                    bf(MoveY, MoveX, st_y, st_x, num + 1, dir);
                else
                    bf(MoveY, MoveX, y, x, 2, 1);
            }

            else if (x == MoveX)
            { // 세로
                if (dir == 2)
                    bf(MoveY, MoveX, st_y, st_x, num + 1, dir);

                else
                    bf(MoveY, MoveX, y, x, 2, 2);
            }

            else if (y - MoveY == 1 && MoveX - x == 1)
            { // 위 대각선
                if (dir == 3)
                    bf(MoveY, MoveX, st_y, st_x, num + 1, dir);
                else
                    bf(MoveY, MoveX, y, x, 2, 3);
            }

            else
            { //아래 대각선
                if (dir == 4)
                    bf(MoveY, MoveX, st_y, st_x, num + 1, dir);
                else
                    bf(MoveY, MoveX, y, x, 2, 4);
            }
        }
    }

    Check[y][x] = false;

    if (num == 5)
    {
        if (dir == 1)
        {
            if ((x > 4 && board[y][x] == board[y][x - 5]) ||
                (x < 18 && board[y][x] == board[y][x + 1]))
                return;
        }
        else if (dir == 2)
        {
            if ((y > 4 && board[y][x] == board[y - 5][x]) ||
                (y < 18 && board[y][x] == board[y + 1][x]))
                return;
        }
        else if (dir == 3)
        {
            if ((y < 14 && x > 4 && board[y][x] == board[y + 5][x - 5]) ||
                (y > 0 && x < 18 && board[y][x] == board[y - 1][x + 1]))
                return;
        }
        else if (dir == 4)
        {
            if ((y > 4 && x > 4 && board[y][x] == board[y - 5][x - 5]) ||
                (y < 18 && x < 18 && board[y][x] == board[y + 1][x + 1]))
                return;
        }

        cout << board[y][x] << "\n" << st_y << " " << st_x << "\n";

        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if ((board[i][j] == 1 || board[i][j] == 2) && !Check[i][j])
                bf(i, j, i, j, 1, 0);
        }
    }

    cout << 0 << "\n";
    return 0;
}