// 14502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int vecBoard[9][9] = {};
bool vecCheck[9][9] = { false, }; 
std::vector<std::pair<int, int>> vecVirus;
int Count = 0;
int N = 0; 
int M = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(std::vector<std::pair<int, int>> vecPos)
{
    // 벽세우기
    for (std::pair<int, int> Coord : vecPos)
        vecBoard[Coord.first][Coord.second] = 1;
    
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < vecVirus.size(); ++i)
    {
        q.push(std::make_pair(vecVirus[i].first, vecVirus[i].second));

        vecCheck[vecVirus[i].first][vecVirus[i].second] = true;

        while (!q.empty())
        {
            int VirusX = q.front().first;
            int VirusY = q.front().second;
            q.pop();

            for (int j = 0; j < 4; ++j)
            {
                int NextX = VirusX + dx[j];
                int NextY = VirusY + dy[j];

                if ((NextX > 0 && NextX <= N) &&
                    (NextY > 0 && NextY <= M))
                {
                    if (!vecCheck[NextX][NextY] && vecBoard[NextX][NextY] == 0)
                    {
                        vecCheck[NextX][NextY] = true;
                        q.push(std::make_pair(NextX, NextY));
                    }
                }
            }
        }
    }


    int CurCount = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (vecBoard[i][j] == 0 && !vecCheck[i][j])
                ++CurCount;
        }
    }

    if (Count < CurCount)
        Count = CurCount;

    std::fill(vecCheck[0], vecCheck[0] + 81, false);
    // 벽치우기
    for (std::pair<int, int> Coord : vecPos)
        vecBoard[Coord.first][Coord.second] = 0;
}

void Comb(int start, int n, int depth, std::vector<std::pair<int, int>> vec, std::vector<std::pair<int, int>> v)
{
    if (v.size() == depth)
    {
        BFS(v);
        return;
    }

    for (int i = start + 1; i < n; i++)
    {
        v.push_back(vec[i]);
        Comb(i, n, depth, vec, v);
        v.pop_back();
    }
    return;
}


int main()
{
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> vecSpace;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            std::cin >> vecBoard[i][j];

            if (vecBoard[i][j] == 0)
                vecSpace.push_back(std::make_pair(i, j));
            else if (vecBoard[i][j] == 2)
                vecVirus.push_back(std::make_pair(i, j));
        }
    }
    
    std::vector<std::pair<int, int>> vecComb;

    Comb(-1, vecSpace.size(), 3, vecSpace, vecComb);

    std::cout << Count;
}
