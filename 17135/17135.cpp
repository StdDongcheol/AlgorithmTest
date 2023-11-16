// 17135.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> vecSrcMap;
std::vector<std::vector<int>> vecMap;
std::vector<bool> vecBow;

int N, M, D;
int MaxCount = 0;

struct compare
{
    bool operator()(std::pair<int, std::pair<int, int>> _l, std::pair<int, std::pair<int, int>> _r)
    {
        if (_l.first == _r.first)
        {
            return _l.second.first > _r.second.first;
        }

        return _l.first > _r.first;
    }
};

void Move()
{
    for (int i = 0; i < M; ++i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            if (vecMap[j][i] > 1)
            {
                vecMap[j][i] = 0;
            }
            else if (vecMap[j][i] == 1)
            {
                if (j + 1 >= N)
                {
                    vecMap[j][i] = 0;
                }
                else
                {
                    vecMap[j][i] = 0;
                    vecMap[j + 1][i] = 1;
                }
            }
        }
    }
}

bool FindTarget(int _CurX, int _CurY)
{
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, compare> pq;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int Dist = abs(i - _CurY) + abs(j - _CurX);

            if (D >= Dist && vecMap[i][j] >= 1)
            {
                pq.push({ Dist, {j, i} });
            }
        }
    }
    
    if (!pq.empty())
    {
        int TargetX = pq.top().second.first;
        int TargetY = pq.top().second.second;

        if (vecMap[TargetY][TargetX] == 1)
        {
            vecMap[TargetY][TargetX] += 1;
            return true;
        }
        else
            vecMap[TargetY][TargetX] += 1;
    }

    return false;
}

int Attack()
{
    int Count = 0;
    for (int i = 0; i < vecBow.size(); ++i)
    {
        if (vecBow[i] == true)
        {
            int CurX = i, CurY = N;
            if (FindTarget(CurX, CurY))
            {
                ++Count;
            }
        }
    }

    return Count;
}

bool IsEnd()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (vecMap[i][j] >= 1)
            {
                return false;
            }
        }
    }

    return true;
}

void Defence()
{
    vecMap = vecSrcMap;
    int CurCount = 0;
    while (!IsEnd())
    {
        CurCount += Attack();
        Move();
    }

    MaxCount = std::max(CurCount, MaxCount);

    return;
}

void Comb(int _CurBowIndex, int _CurBowCount)
{
    vecBow[_CurBowIndex] = true;

    if (_CurBowCount == 3)
    {
        Defence();

        vecBow[_CurBowIndex] = false;
        return;
    }

    for (int i = _CurBowIndex + 1; i < M; ++i)
    {
        Comb(i, _CurBowCount + 1);
    }

    vecBow[_CurBowIndex] = false;
}

int main()
{
    std::cin >> N >> M >> D; 

    vecMap.resize(N);
    vecSrcMap.resize(N);
    vecBow.resize(M);
    for (int i = 0; i < N; ++i)
    {
        vecMap[i].resize(M);
        vecSrcMap[i].resize(M);

        for (int j = 0; j < M; ++j)
        {
            std::cin >> vecSrcMap[i][j];
        }
    }
    
    for (int i = 0; i < M - 2; ++i)
    {
        Comb(i, 1);
    }


    std::cout << MaxCount;

    return 0;
}
