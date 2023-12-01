// p10879.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int R, C, MaxCount, MinCount;
std::vector<vector<bool>> vecCheck;
std::vector<vector<int>> vecBoard;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool IsAlive(int _X, int _Y)
{
    bool IsMove = false;
    
    if (vecBoard[_Y][_X] == 0)
        return false;

    else
    {
        for (int i = 0; i < 4; ++i)
        {
            if (vecBoard[_Y][_X] == 1)
                IsMove = true;
        }
    }

    return IsMove;
}


// _MoveTurn : 0 << A차례
// _MoveTurn : 1 << B차례
int DFS(int _CurAX, int _CurAY, int _CurBX, int _CurBY, int _CurMove, int _MoveTurn)
{
    bool Check = false;
    int Count = _CurMove;

    if (_MoveTurn == 0)
    {
        if (IsAlive(_CurAX, _CurAY))
        {
            for (int i = 0; i < 4; ++i)
            {
                int NextX = _CurAX + dx[i];
                int NextY = _CurAY + dy[i];

                if (0 <= NextX && NextX < C && 0 <= NextY && NextY < R && vecBoard[NextY][NextX] == 1)
                {
                    int CurCount = 0;
                    vecBoard[_CurAY][_CurAX] = 0;
                    CurCount = DFS(NextX, NextY, _CurBX, _CurBY, _CurMove + 1, 1);
                    vecBoard[_CurAY][_CurAX] = 1;
                    if (CurCount != -1)
                    {
                        Check = true;
                        MinCount = std::min(CurCount, Count);
                    }
                }
            }

            if (Check == false)
            {
                MaxCount = std::max(MaxCount, _CurMove);
                return;
            }
        }
        else
        {
            MaxCount = std::max(MaxCount, _CurMove);
            return;
        }
    }

    else
    {
        if (IsAlive(_CurBX, _CurBY))
        {
            for (int i = 0; i < 4; ++i)
            {
                int NextX = _CurBX + dx[i];
                int NextY = _CurBY + dy[i];

                if (0 <= NextX && NextX < C && 0 <= NextY && NextY < R && vecBoard[NextY][NextX] == 1)
                {
                    Check = true;
                    vecBoard[_CurBY][_CurBX] = 0;
                    DFS(_CurAX, _CurAY, NextX, NextY, _CurMove + 1, 0);
                    vecBoard[_CurBY][_CurBX] = 1;
                }
            }

            if (Check == false)
            {
                MaxCount = std::max(MaxCount, _CurMove);
                return;
            }
        }
        else
        {
            MaxCount = std::max(MaxCount, _CurMove);
            return;
        }
    }

    return;
}

// (r, c) 좌표기준임
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    vecBoard = board;
    int answer = -1;
    R = board.size();
    C = board[0].size();
    vecCheck.resize(board.size());
    for (int i = 0; i < vecCheck.size(); ++i)
        vecCheck[i].resize(board[i].size());

    DFS(aloc[1], aloc[0], bloc[1], bloc[0], 0, 0);
    answer = MaxCount;
    return answer;
}


int main()
{
    solution({ {1, 1,1},{1,1,1,},{1,1,1} }, { 1, 0 }, {1, 2});
}
