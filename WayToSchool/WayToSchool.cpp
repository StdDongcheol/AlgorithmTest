// WayToSchool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

std::vector<std::vector<int>> vecMap;
int arrMap[100][100] = {};
int dpMap[100][100] = {};
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int CoordN = 0;
int CoordM = 0;

int DFS(int x, int y)
{
    if (x == CoordM && y == CoordN)
        return 1;

    if (dpMap[y][x] != 0)
        return dpMap[y][x];


    for (int i = 0; i < 2; ++i)
    {
        int NextX = x + dx[i];
        int NextY = y + dy[i];

        if (NextX <= CoordM && NextX > 0 && NextY <= CoordN && NextY > 0)
        {
            if (arrMap[NextY][NextX] == -1)
                continue;

            dpMap[y][x] += DFS(NextX, NextY) % 1000000007;
        }
    }

    return dpMap[y][x] % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    CoordN = n;
    CoordM = m;
    std::fill(arrMap[0], arrMap[0] + 10000, 1);
    std::fill(dpMap[0], dpMap[0] + 10000, 0);

    for (int i = 0; i < puddles.size(); ++i)
    {
        int PudX = puddles[i][0];
        int PudY = puddles[i][1];
        arrMap[PudY][PudX] = -1;
    }

    int Count = DFS(1, 1) % 1000000007;

    answer = Count % 1000000007;

    return answer;
}

int main()
{
    solution(4, 3, { {2, 2} });
}
