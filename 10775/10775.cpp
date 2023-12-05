// 10775.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

std::vector<int> vecIndex;

int Find(int _index)
{
    if (vecIndex[_index] == _index)
        return _index;

    else
    {
        vecIndex[_index] = Find(vecIndex[_index]);
        return vecIndex[_index];
    }
}

void Union(int _IndexA, int _IndexB)
{
    int A = Find(_IndexA);
    int B = Find(_IndexB);

    if (A != B)
    {
        vecIndex[A] = B;
    }
}

int main()
{
    int G, P, Count = 0;
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    std::cin >> G >> P;
    std::vector<int> vec(G + 1, 0);
    std::queue<int> q;

    vecIndex.resize(G + 1);
    for (int i = 1; i <= G; ++i)
        vecIndex[i] = i;

    for (int i = 0; i < P; ++i)
    {
        int Plane = 0;
        std::cin >> Plane;

        q.push(Plane);
    }


    while (!q.empty())
    {
        int CurPlane = q.front();
        q.pop();

        int CurIndex = Find(CurPlane);
            
        if (CurIndex <= 0)
            break;

        else
        {
            Union(CurIndex, CurIndex - 1);
            ++Count;
        }
    }

    std::cout << Count;

    return 0;
}