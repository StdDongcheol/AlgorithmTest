// 5427.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

char arr[1000][1000];
bool check[1000][1000];
bool moveCheck[1000][1000];
int mapRun[1000][1000];

int T, W, H;
bool RunCheck = false;
std::queue<std::pair<int, int>> queueFire;
int resValue = 999999999;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int _x, int _y)
{
    std::queue<std::pair<int, int>> q;
    std::queue<std::pair<int, int>> moveQ;
    std::queue<std::pair<int, int>> fireQ;
    q.push({ _x, _y });
    
    mapRun[_y][_x] = 1;
    moveCheck[_y][_x] = true;

    while (!q.empty())
    {
        // 불먼저 1회 BFS 탐색
        while (!queueFire.empty())
        {
            int CurX = queueFire.front().first;
            int CurY = queueFire.front().second;
            check[CurY][CurX] = true;
            arr[CurY][CurX] = '*';
            queueFire.pop();

            for (int i = 0; i < 4; ++i)
            {
                int NextX = CurX + dx[i];
                int NextY = CurY + dy[i];
                
                if (0 <= NextX && NextX < W && 0 <= NextY && NextY < H && check[NextY][NextX] == false)
                {
                    if (arr[NextY][NextX] == '.' || arr[NextY][NextX] == '@')
                    {
                        check[NextY][NextX] = true;
                        fireQ.push({ NextX, NextY });
                    }
                }
            }
        }

        // 불 queue 충전
        while (!fireQ.empty())
        {
            queueFire.push(fireQ.front());
            fireQ.pop();
        }
        
        // movequeue 충전
        while (!q.empty())
        {
            moveQ.push(q.front());
            q.pop();
        }

        while (!moveQ.empty())
        {
            int CurX = moveQ.front().first;
            int CurY = moveQ.front().second;
            moveQ.pop();

            for (int i = 0; i < 4; ++i)
            {
                int NextX = CurX + dx[i];
                int NextY = CurY + dy[i];

                if (0 <= NextX && NextX < W && 0 <= NextY && NextY < H)
                {
                    if (moveCheck[NextY][NextX] == false && check[NextY][NextX] == false && arr[NextY][NextX] == '.')
                    {
                        mapRun[NextY][NextX] = mapRun[CurY][CurX] + 1;
                        moveCheck[NextY][NextX] = true;
                        q.push({ NextX, NextY });
                    }
                }

                // 탈출성공
                else
                {
                    resValue = std::min(mapRun[CurY][CurX], resValue);
                    break;
                }
            }
        }
    }

    return;
}

int main()
{
    int PosX, PosY;

    std::cin >> T;

    for (int k = 0; k < T; ++k)
    {
        std::cin >> W >> H;

        for (int i = 0; i < H; ++i)
        {
            std::string str;
            std::cin >> str;
            for (int j = 0; j < W; ++j)
            {
                arr[i][j] = str[j];

                if (arr[i][j] == '*')
                    queueFire.push({ j, i });

                else if (arr[i][j] == '@')
                {
                    PosX = j;
                    PosY = i;
                }
            }
        }

        BFS(PosX, PosY);

        if (resValue == 999999999)
            std::cout << "IMPOSSIBLE\n";
        else
            std::cout << resValue << "\n";

        std::fill(check[0], check[0] + 1000000, false);
        std::fill(moveCheck[0], moveCheck[0] + 1000000, false);
        std::fill(mapRun[0], mapRun[0] + 1000000, 0);

        resValue = 999999999;

        while (!queueFire.empty())
        {
            queueFire.pop();
        }
    }

    return 0;
}
