// 8979.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct Country
{
    int Numb;
    int G;
    int S;
    int B;
    int Rank;
};

bool comp(Country a, Country b) 
{
    if (a.G > b.G) 
    {
        return true;
    }

    else if (a.G == b.G) 
    {
        if (a.S > b.S) 
        {
            return true;
        }
        else if (a.S == b.S) 
        {
            if (a.B > b.B) 
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }

    else 
    {
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<Country> vec;

    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        Country C;
        
        std::cin >> C.Numb >> C.G >> C.S >> C.B;
        C.Rank = 1;
        vec.push_back(C);
    }

    std::sort(vec.begin(), vec.end(), comp);

    int RankIndex = 0;
    for (int i = 0; i < N; ++i)
    {
        if (vec[i].Numb == K)
        {
            RankIndex = i;
            break;
        }
    }

    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i].G == vec[i - 1].G && vec[i].S == vec[i - 1].S && vec[i].B == vec[i - 1].B)
        {
            vec[i].Rank = vec[i - 1].Rank;
        }
        else
            vec[i].Rank = i + 1;
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i].Numb == K)
        {
            std::cout << vec[i].Rank;
            return 0;
        }
    }

    return 0;
}
