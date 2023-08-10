// IslandTravel.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

char arr[100][100];
bool check[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int BFS(int _x, int _y)
{
    std::queue<std::pair<int, int>> q;
    q.push({ _x, _y });
    check[_y][_x] = true;

    int Sum = (int)(arr[_y][_x] - '0');

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextX < N && NextX >= 0 && NextY < M && NextY >= 0)
            {
                if (arr[NextY][NextX] != 'X' && !check[NextY][NextX])
                {
                    int Numb = (int)(arr[NextY][NextX] - '0');
                    Sum += Numb;
                    check[NextY][NextX] = true;
                    q.push({ NextX, NextY });
                }
            }
        }
    }

    return Sum;
}

std::vector<int> solution(std::vector<std::string> maps)
{
    std::vector<int> answer;
    M = maps.size();
    N = maps[0].size();

    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            arr[i][j] = maps[i][j];
        }
    }

    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (arr[i][j] != 'X' && !check[i][j])
                answer.push_back(BFS(j, i));
        }
    }

    if (answer.empty())
        answer.push_back(-1);
    std::sort(answer.begin(), answer.end());
    return answer;
}



int main()
{
    solution({ "X591X","X1X5X","X231X", "1XXX1" });
}

