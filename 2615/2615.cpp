#include <iostream>
#include <vector>
std::vector<std::vector<int>> vecBoard;
int board[19][19] = {};
bool Check[19][19] = {};
int dx[4] = { 1, 0, 1, 1};
int dy[4] = { 0, 1, -1,  1};
int CurX, CurY;
int MoveX;
int MoveY;
void DFS(int Y, int X, int Dir, int Count, int Force)
{
    Check[Y][X] = true;

    for (int i = 0; i < 4; ++i)
    {
        MoveX = X + dx[i];
        MoveY = Y + dy[i];

        if (MoveX >= 19 || MoveX < 0 || MoveY >= 19 || MoveY < 0)
            continue;

        if (board[MoveY][MoveX] == board[Y][X] 
            && !Check[MoveY][MoveX])
        {
            // 가로의 경우
            if (MoveY == Y)
            {
                if (Dir == 0)
                    DFS(MoveY, MoveX, Dir, Count + 1, Force);
                else
                    DFS(MoveY, MoveX, 0, 2, Force);
            }

            // 세로의 경우
            else if (MoveX == X)
            {
                if (Dir == 1)
                    DFS(MoveY, MoveX, Dir, Count + 1, Force);
                else
                    DFS(MoveY, MoveX, 1, 2, Force);
            }

            // 위대각선의 경우
            else if (Y - MoveY == 1 && MoveX - X == 1)
            {
                if (Dir == 2)
                    DFS(MoveY, MoveX, Dir, Count + 1, Force);
                else
                    DFS(MoveY, MoveX, 2, 2, Force);
            }

            else
            {
                if (Dir == 3)
                    DFS(MoveY, MoveX, Dir, Count + 1, Force);
                else
                    DFS(MoveY, MoveX, 3, 2, Force);
            }
        }
    }

    Check[Y][X] = false;

    if (Count == 5)
    {
        if (Dir == 0)
        {
            if ((X > 5 && board[Y][X] == board[Y][X - 5]) ||
                (X < 19 && board[Y][X] == board[Y][X + 1]))
                return;
        }
        
        else if (Dir == 1)
        {
            if ((Y > 5 && board[Y][X] == board[Y - 5][X]) ||
                (Y < 19 && board[Y][X] == board[Y + 1][X]))
                return;
        }
        
        else if (Dir == 2)
        {
            if ((Y < 15 && X > 5 && board[Y][X] == board[Y + 5][X - 5]) ||
                (Y > 1 && X < 19 && board[Y][X] == board[Y - 1][X + 1]))
                return;
        }
        
        else if (Dir == 3)
        {
            if ((Y > 5 && X > 5 && board[Y][X] == board[Y - 5][X - 5]) ||
                (Y < 19 && X < 19 && board[Y][X] == board[Y + 1][X + 1]))
                return;
        }

        std::cout << board[Y][X] << "\n";
        std::cout << CurY + 1 << " " << CurX + 1;
        exit(0);
    }

    return;
}

int main()
{
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            std::cin >> board[i][j];
        }
    }


    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            if (!Check[i][j] && board[i][j] != 0)
            {
                CurX = j;
                CurY = i;
                DFS(i, j, 0, 1, board[i][j]);
            }
        }
    }

    std::cout << "0";
    
    return 0;
}
