// 11123.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

int T;
int H, W;

char arr[100][100];
bool check[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int _x, int _y)
{
    std::queue<std::pair<int, int>> q;
    check[_y][_x] = true;
    q.push({_x, _y});

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextX < W && NextX >= 0 && NextY < H && NextY >= 0 && !check[NextY][NextX] && arr[NextY][NextX] == '#')
            {
                check[NextY][NextX] = true;
                q.push({NextX, NextY});
            }
        }
    }
}

int main()
{
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        // 3, 5
        std::cin >> H >> W;
        
        for (int j = 0; j < H; ++j)
        {
            std::string str;
            std::cin >> str;
            for (int k = 0; k < str.size(); ++k)
            {
                arr[j][k] = str[k];
            }
        }
        
        int Count = 0;
        for (int j = 0; j < H; ++j)
        {
            for (int k = 0; k < W; ++k)
            {
                if (arr[j][k] == '#' && !check[j][k])
                {
                    BFS(k, j);
                    ++Count;
                }
            }
        }
        
        std::cout << Count << '\n';
        std::fill(check[0], check[0] + 10000, false);
    }


}
