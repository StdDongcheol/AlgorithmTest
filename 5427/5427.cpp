// 5427.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

char arr[1000][1000];
bool check[1000][1000];
int map[1000][1000];
int mapRun[1000][1000];
int mapBurn[1000][1000];

int T, W, H;
bool RunCheck = false;
std::queue<std::pair<int, int>> queueFire;
std::vector<int> vecValue;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int _x, int _y, bool burning, bool Run)
{
    std::queue<std::pair<int, int>> q;

    if (!burning)
    {
        check[_y][_x] = true;
        q.push({ _x, _y });
    }
    
    else
    {
        while (!queueFire.empty())
        {
            q.push(queueFire.front());
            queueFire.pop();
        }
    }

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (Run)
            {
                if ((NextX >= W || NextX < 0 || NextY >= H || NextY < 0))
                {
                    RunCheck = true;
                    vecValue.push_back(mapRun[CurY][CurX]);
                }

                else if (NextX < W && NextX >= 0 && NextY < H && NextY >= 0)
                {
                    if (map[NextY][NextX] > 0 && !check[NextY][NextX])
                    {
                        check[NextY][NextX] = true;
                        q.push({ NextX, NextY });
                    }
                }
            }
            else if (NextX < W && NextX >= 0 && NextY < H && NextY >= 0 && arr[NextY][NextX] != '#')
            {
                if (burning && arr[NextY][NextX] != '*')
                {
                    mapBurn[NextY][NextX] += mapBurn[CurY][CurX] + 1;
                    map[NextY][NextX] = mapBurn[NextY][NextX] - map[NextY][NextX];
                    arr[NextY][NextX] = '*';

                    q.push({ NextX, NextY });
                }
                else if(!burning && check[NextY][NextX] == false)
                {
                    check[NextY][NextX] = true;
                    map[NextY][NextX] += map[CurY][CurX] + 1;
                    mapRun[NextY][NextX] += mapRun[CurY][CurX] + 1;
                    q.push({ NextX, NextY });
                }
            }
        }
    }

    return -1;
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

        BFS(PosX, PosY, false, false);
        BFS(PosX, PosY, true, false);

        std::fill(check[0], check[0] + 1000000, false);
        int Value = BFS(PosX, PosY, false, true);
        
        if (vecValue.empty())
            std::cout << "IMPOSSIBLE\n";
        else
        {
            Value = *std::min_element(vecValue.begin(), vecValue.end()) + 1;
            std::cout << Value << '\n';
        }

        std::fill(check[0], check[0] + 1000000, false);
        std::fill(map[0], map[0] + 1000000, 0);
        std::fill(mapRun[0], mapRun[0] + 1000000, 0);
        std::fill(mapBurn[0], mapBurn[0] + 1000000, 0);
        vecValue.clear();
        while (!queueFire.empty())
        {
            queueFire.pop();
        }
    }

    return 0;
}
