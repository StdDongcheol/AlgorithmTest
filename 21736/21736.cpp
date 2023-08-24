// 21736.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <queue>

char arr[600][600];
bool check[600][600];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int _x, int _y)
{
    int Count = 0;
    std::queue<std::pair<int, int>> q;
    q.push({_x, _y});

    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        if (arr[CurY][CurX] == 'P')
            ++Count;

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextX < M && NextX >= 0 && NextY < N && NextY >= 0 && !check[NextY][NextX])
            {
                if (arr[NextY][NextX] == 'O' || arr[NextY][NextX] == 'P')
                {
                    q.push({ NextX, NextY }); 
                    check[NextY][NextX] = true;
                }
            }
        }
    }

    return Count;
}

int main()
{
    std::cin >> N >> M;
    int StartX, StartY;
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        std::cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            arr[i][j] = str[j];
            if (str[j] == 'I')
            {
                StartX = j;
                StartY = i;
            }
        }
    }

    int Person = BFS(StartX, StartY);

    if (Person <= 0)
        std::cout << "TT";
    else
        std::cout << Person;

    return 0;
}