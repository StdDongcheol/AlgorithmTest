// 15686_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int map[51][51];
std::vector<std::pair<int, int>> vecChick;
std::vector<std::pair<int, int>> vecHouse;
std::vector<int> vecDist;

void Comb(int _CurM, int _ChickIndex, std::vector<std::pair<int, int>>& _vecSelect)
{
    if (_CurM == M)
    {
        int SumDist = 0;
        for (int i = 0; i < vecHouse.size(); ++i)
        {
            int HomeX = vecHouse[i].first;
            int HomeY = vecHouse[i].second;
            int Dist = 999999999;

            for (int j = 0; j < _vecSelect.size(); j++)
            {
                int ChickX = _vecSelect[j].first;
                int ChickY = _vecSelect[j].second;
                int CurDist = abs(HomeX - ChickX) + abs(HomeY - ChickY);

                Dist = std::min(Dist, CurDist);
            }

            SumDist += Dist;
        }
        
        vecDist.push_back(SumDist);

        return;
    }

    for (int i = _ChickIndex; i < vecChick.size(); ++i)
    {
        int CurX, CurY;
        CurX = vecChick[i].first;
        CurY = vecChick[i].second;

        _vecSelect.push_back({ CurX , CurY });
        Comb(_CurM + 1, i + 1, _vecSelect);
        _vecSelect.pop_back();
    }
}

int main()
{
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 1)
                vecHouse.push_back({ j, i });
            else if (map[i][j] == 2)
                vecChick.push_back({ j, i });
        }
    }

    std::vector<std::pair<int, int>> vec;
    Comb(0, 0, vec);
    
    std::sort(vecDist.begin(), vecDist.end());

    std::cout << vecDist[0];
    return 0;
}
