// 7576.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <queue>
#include <algorithm>

int arrMap[1001][1001];
bool arrCheck[1001][1001];

int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Day = 0;
std::queue<std::pair<int, int>> q;

void BFS()
{
    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        arrCheck[CurY][CurX] = true;

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (NextY <= M && NextY >= 1 && NextX <= N && NextX >= 1)
            {
                if (!arrCheck[NextY][NextX] && arrMap[NextY][NextX] == 0)
                {
                    q.push({ NextX, NextY });
                    arrMap[NextY][NextX] = arrMap[CurY][CurX] + 1;
                }
            }
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    std::cin >> N >> M;
    std::queue<std::pair<int, int>> NextVec;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            std::cin >> arrMap[i][j];
            if (arrMap[i][j] == 1)
                q.push({ j, i });
        }
    }

    BFS();

    bool Check = false;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (arrMap[i][j] == 0)
            {
                Check = true;
                break;
            }
            else
            {
                Day = std::max(Day, arrMap[i][j]);
            }
        }
    }

    if (Check)
        std::cout << -1;
    else
        std::cout << Day - 1;
}
