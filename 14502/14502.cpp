// 14502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int vecBoard[8][8] = {};
bool vecCheck[8][8] = { false, }; 
std::vector<std::pair<int, int>> vecVirus;
int Count = 0;
int N, M;

int BFS(std::vector<std::pair<int, int>> vecPos)
{
    // 벽세우기
    for (std::pair<int, int> Coord : vecPos)
        vecBoard[Coord.first][Coord.second] = 1;





    // 벽치우기
    for (std::pair<int, int> Coord : vecPos)
        vecBoard[Coord.first][Coord.second] = 0;
}

void Comb(int start, int n, int depth, std::vector<std::pair<int, int>> vec, std::vector<std::pair<int, int>> v)
{
    if (v.size() == depth)
    {

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



    std::cout << "Hello World!\n";
}
