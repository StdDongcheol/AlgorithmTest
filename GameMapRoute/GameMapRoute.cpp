// GameMapRoute.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<bool>> m_vecCheck;
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { 1, 0, -1 , 0 };



int solution(std::vector<std::vector<int>> maps)
{
    std::queue<std::pair<int, int>> queue;
    int answer = 0;
    
    int X, Y;
    int N, M;

    bool Check = false;
    N = maps.size() - 1;
    M = maps[0].size() - 1;

    m_vecCheck.resize(maps.size());

    for (int i = 0; i < m_vecCheck.size(); ++i)
    {
        m_vecCheck[i].resize(maps[0].size(), false);
    }

    queue.push(std::make_pair(0, 0));

    while (!queue.empty())
    {
        X = queue.front().first;
        Y = queue.front().second;
        queue.pop();

        if (X == N && Y == M)
        {
            Check = true;
            return maps[X][Y];
        }

        for (int i = 0; i < 4; ++i)
        {
            int CoordX = X + dx[i];
            int CoordY = Y + dy[i];
            
            if ((CoordX > N || CoordX < 0) || (CoordY > M || CoordY < 0))
                continue;

            if (maps[CoordX][CoordY] == 1 && !m_vecCheck[CoordX][CoordY])
            {
                m_vecCheck[CoordX][CoordY] = true;
                maps[CoordX][CoordY] += maps[X][Y];
                queue.push(std::make_pair(CoordX, CoordY));
            }
        }
    }

    if (!Check)
        answer = -1;

    return answer;
}

int main()
{
    std::vector<std::vector<int>> vec = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} };

    solution(vec);
    std::cout << "Hello World!\n";
}