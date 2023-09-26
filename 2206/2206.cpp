// 2206.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

int arrMap[1000][1000][2];

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

enum State
{
    Stay = 0,
    Break = 1
};

int BFS(int _x, int _y)
{
    std::queue<std::pair<std::pair<int, int>, State>> q;
    q.push({ { _x, _y }, State::Stay });

    while (!q.empty())
    {
        int CurX = q.front().first.first;
        int CurY = q.front().first.second;
        State CurState = q.front().second;
        q.pop();

        if (CurX == M - 1 && CurY == N - 1)
        {
            return arrMap[CurY][CurX][CurState] + 1;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = dx[i] + CurX;
            int NextY = dy[i] + CurY;

            if (NextX >= 0 && NextX < M && NextY >= 0 && NextY < N)
            {
                // 벽일경우
                if (arrMap[NextY][NextX][0] == 1)
                {
                    if (CurState == State::Stay)
                    {
                        arrMap[NextY][NextX][State::Break] = arrMap[CurY][CurX][CurState] + 1;
                        q.push({{ NextX, NextY }, State::Break });
                    }
                }

                // 통로일경우
                else if (arrMap[NextY][NextX][0] == 0)
                {
                    if (CurState == State::Break && arrMap[NextY][NextX][CurState] > 0)
                    {
                        continue;
                    }

                    arrMap[NextY][NextX][CurState] = arrMap[CurY][CurX][CurState] + 1;
                    q.push({ { NextX, NextY }, CurState });
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < str.size(); ++j)
        {
            arrMap[i][j][0] = str[j] - '0';
        }
    }

    std::cout << BFS(0, 0);
    
    return 0;
}
