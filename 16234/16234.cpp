// 16234.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int N, L, R;
int arrMap[50][50];
bool check[50][50];
std::queue<std::vector<std::pair<int, int>>> vecQ;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void MoveDay(std::vector<std::pair<int, int>> _vec)
{
    int Sum = 0;
    int CurSize = _vec.size();

    for (size_t i = 0; i < _vec.size(); i++)
    {
        int CurX = _vec[i].first;
        int CurY = _vec[i].second;

        Sum += arrMap[CurY][CurX];
    }
    
    int Average = Sum / CurSize;
    
    for (size_t i = 0; i < _vec.size(); i++)
    {
        int CurX = _vec[i].first;
        int CurY = _vec[i].second;

        arrMap[CurY][CurX] = Average;
    }

    return;
}

// L R 조건에 따라 인접타일 비교
// 후 q에 추가
void BFS(int _x, int _y)
{
    std::vector<std::pair<int, int>> _vec;
    std::queue<std::pair<int, int>> q;

    check[_y][_x] = true;
    q.push({ _x, _y });
    
    while (!q.empty())
    {
        int CurX = q.front().first;
        int CurY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextX = CurX + dx[i];
            int NextY = CurY + dy[i];

            if (0 <= NextX && NextX < N && 0 <= NextY && NextY < N && check[NextY][NextX] == false)
            {
                int Sum = abs(arrMap[NextY][NextX] - arrMap[CurY][CurX]);
                if (Sum >= L && Sum <= R)
                {
                    check[NextY][NextX] = true;
                    _vec.push_back({ NextX, NextY });
                    q.push({ NextX, NextY });
                }
            }
        }
    }

    if (!_vec.empty())
    {
        _vec.push_back({ _x, _y });
        vecQ.push(_vec);
    }

    return;
}

int main()
{
    int Day = 0;
    std::cin >> N >> L >> R;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arrMap[i][j];
        }
    }
    
    
    bool DayCheck = false;
    do
    {
        DayCheck = false;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; j++)
            {
                if (check[i][j] == false)
                {
                    BFS(j, i);
                }
            }
        }

        if (!vecQ.empty())
        {
            DayCheck = true;
            ++Day;
            while (!vecQ.empty())
            {
                MoveDay(vecQ.front());
                vecQ.pop();
            }
        }

        std::fill(check[0], check[0] + 2500, false);

    } while (DayCheck);

    std::cout << Day;

    return 0;
}
