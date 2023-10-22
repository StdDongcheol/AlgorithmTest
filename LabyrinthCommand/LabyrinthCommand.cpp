// LabyrinthCommand.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

std::vector<std::vector<char>> vecMap;
std::string resultStr;
// 1:d  2:l  3:r  4:u
int dx[4] = { 0, -1, 1 , 0 };
int dy[4] = { 1, 0, 0, -1 };
char arr[4] = {'d', 'l', 'r', 'u'};

void DFS(std::string _Str, int _CurCount, 
    int _n, int _m, int _x, int _y, int _r, int _c, int _k)
{
    if (resultStr.empty())
    {
        string CurStr = _Str;
        int CurX = _x;
        int CurY = _y;

        if (_CurCount == _k)
        {
            if (vecMap[CurY][CurX] == 'E')
            {
                resultStr = _Str;
                return;
            }
        }

        int Dist = abs(CurX - _c) + abs(CurY - _r);

        if (CurStr.length() + Dist > _k)
            return;
        else
        {
            int MoveCount = abs(_k - (int)CurStr.length() - Dist);

            if (MoveCount % 2 != 0)
                return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];
            if (1 <= NextX && NextX <= _m && 1 <= NextY && NextY <= _n)
            {
                CurStr.push_back(arr[i]);
                DFS(CurStr, _CurCount + 1, _n, _m, NextX, NextY, _r, _c, _k);
                CurStr.pop_back();
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

    std::string Str;

    DFS(Str, 0, n, m, y, x, r, c, k);

    if (!resultStr.empty())
        answer = resultStr;
    else
        answer = "impossible";

    return resultStr;
}

int main()
{
    solution(3, 4, 2, 3, 3, 1, 5);

    return 1;
}

