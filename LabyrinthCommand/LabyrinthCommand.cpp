// LabyrinthCommand.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

std::vector<std::vector<char>> vecMap;

// 1:d  2:l  3:r  4:u
int dx[4] = { 0, -1, 1 , 0 };
int dy[4] = { 1, 0, 0, -1 };

void BFS(std::vector<string>& _vecStr,
    int _n, int _m, int _x, int _y, int _r, int _c, int _k)
{
    std::queue<std::pair<string, std::pair<int, int>>> q;

    q.push({ "", {_x, _y} });

    while (!q.empty())
    {
        string CurStr = q.front().first;
        int CurX = q.front().second.first;
        int CurY = q.front().second.second;
        q.pop();

        if (CurStr.length() == _k)
        {
            if (vecMap[CurY][CurX] == 'E')
            {
                _vecStr.push_back(CurStr);
            }
            continue;
        }

        int Dist = abs(CurX - _c) + abs(CurY - _r);


        if (CurStr.length() + Dist > _k)
            continue;
        else
        {
            int MoveCount = abs(_k - (int)CurStr.length() - Dist);

            if (MoveCount % 2 != 0)
                continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];
            if (1 <= NextX && NextX <= _m && 1 <= NextY && NextY <= _n)
            {
                switch (i)
                {
                case 0:
                    q.push({ CurStr + 'd', {NextX, NextY} });
                    break;
                case 1:
                    q.push({ CurStr + 'l', {NextX, NextY} });
                    break;
                case 2:
                    q.push({ CurStr + 'r', {NextX, NextY} });
                    break;
                case 3:
                    q.push({ CurStr + 'u', {NextX, NextY} });
                    break;
                }
            }
        }
    }

    return;
}


string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";

    vecMap.resize(n + 1);
    for (int i = 0; i < vecMap.size(); ++i)
        vecMap[i].resize(m + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            vecMap[i][j] = '.';
        }
    }

    vecMap[r][c] = 'E';

    std::vector<string> vecStr;

    BFS(vecStr, n, m, y, x, r, c, k);

    if (!vecStr.empty())
        answer = vecStr[0];
    else
        answer = "impossible";

    return answer;
}



int main()
{
    solution(3, 4, 2, 3, 3, 1, 5);

    return 1;
}

