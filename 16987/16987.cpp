// 16987.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>


struct Egg
{
    int Index;
    int S;
    int W;
};

int N, MaxCount;
std::vector<Egg> vec;


void DFS(int _index)
{
    if (_index >= N)
    {
        int CurCount = 0;
        for (int i = 0; i < N; ++i)
        {
            if (vec[i].S <= 0)
                ++CurCount;
        }

        MaxCount = std::max(MaxCount, CurCount);
        return;
    }

    Egg CurEgg = vec[_index];

    bool check = false;
    for (int i = 0; i < N; ++i)
    {
        if (i == _index)
            continue;

        if (vec[i].S > 0 && vec[_index].S > 0)
        {
            check = true;
            vec[_index].S -= vec[i].W;
            vec[i].S -= vec[_index].W;
            DFS(_index + 1);
            vec[_index].S += vec[i].W;
            vec[i].S += vec[_index].W;
        }
    }

    if (check == false)
    {
        DFS(_index + 1);
    }

    return;
}

int main()
{
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        Egg E;
        std::cin >> E.S >> E.W;
        E.Index = i;
        vec.push_back(E);
    }

    DFS(0);

    std::cout << MaxCount;

    return 0;
}
