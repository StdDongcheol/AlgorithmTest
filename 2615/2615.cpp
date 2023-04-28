


#include <iostream>
#include <vector>

std::vector<std::vector<int>> vecBoard;

int board[19][19] = {};
bool Check[19][19] = {};

int dx[4] = { 1, 0, -1, 1};
int dy[4] = { 0, 1, 1, 1};

int DFS(int Y, int X, int Dir, int Count, int Force)
{
    Check[Y][X] = true;

    int MoveX = X + dx[Dir];
    int MoveY = Y + dy[Dir];

    if (MoveX >= 19 || MoveX < 0 || MoveY >= 19 || MoveY < 0)
        return Count;

    if (board[MoveY][MoveX] == Force && !Check[MoveY][MoveX])
        Count = DFS(MoveY, MoveX, Dir, Count + 1, Force);
    
    Check[Y][X] = false;

    if (Count == 5)
    {
        int MoveX = X + dx[Dir];
        int MoveY = Y + dy[Dir];

        if (MoveX >= 19 || MoveX < 0 || MoveY >= 19 || MoveY < 0)
            return 0;

        int ReverseMoveX = X - (dx[Dir] * 5);
        int ReverseMoveY = Y - (dy[Dir] * 5);

        if (board[MoveY][MoveX] == Force || board[ReverseMoveY][ReverseMoveX] == Force)
            return 6;
        else
            return Count;
    }

    return Count;
}

int DFSTail(int Y, int X, int Force)
{
    if (board[Y][X] != Force)
        return 0;

    for (int i = 0; i < 4; ++i)
    {
        if (5 == DFS(Y, X, i, 1, Force))
            return 5;
    }

    return 0;
}

int main()
{
    //vecBoard.resize(19);
    //
    //for(int i = 0; i < vecBoard.size(); ++i)
    //    vecBoard[i].resize(19);

    //for (int i = 0; i < vecBoard.size(); ++i)
    //{
    //    for (int j = 0; j < vecBoard[i].size(); ++j)
    //    {
    //        std::cin >> vecBoard[i][j];
    //    }
    //}
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            std::cin >> board[i][j];
        }
    }

    bool BlackCheck = false;
    bool WhiteCheck = false;
    int X, Y;
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            if (DFSTail(i, j, 1) == 5)
            {
                Y = i + 1;
                X = j + 1;
                BlackCheck = true;
                break;
            }

            else if (DFSTail(i, j, 2) == 5)
            {
                Y = i + 1;
                X = j + 1;
                WhiteCheck = true;
                break;
            }
        }

        if (WhiteCheck || BlackCheck)
            break;
    }

    if (BlackCheck)
    {
        std::cout << "1" << "\n";
        std::cout << Y << " " << X;
    }
    else if (WhiteCheck)
    {
        std::cout << "2" << "\n";
        std::cout << Y << " " << X;
    }
    else
    {
        std::cout << "0";
    }

    return 0;
}
