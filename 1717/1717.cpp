// 1717.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<int> vec;

int GetNode(int _Index)
{
    int CurIndex = vec[_Index];

    if (CurIndex == _Index)
        return _Index;

    else
    {
        int NewIndex = GetNode(CurIndex);
        vec[_Index] = NewIndex;
        return NewIndex;
    }
}

bool Find(int _StartIndex, int _EndIndex)
{
    int CurIndex1 = GetNode(_StartIndex);
    int CurIndex2 = GetNode(_EndIndex);

    if (CurIndex1 == CurIndex2)
        return true;
    else
        return false;
}

void Union(int _Start, int _End)
{
    int StartIndex = GetNode(_Start);
    int EndIndex = GetNode(_End);

    if (Find(StartIndex, EndIndex))
    {
        if (StartIndex < EndIndex)
        {
            vec[EndIndex] = StartIndex;
        }
        else
        {
            vec[StartIndex] = EndIndex;
        }
    }
    
    else
    {
        int ConnectSIndex = vec[StartIndex];
        int ConnectEIndex = vec[EndIndex];
    
        if (ConnectSIndex < ConnectEIndex)
        {
            vec[ConnectEIndex] = ConnectSIndex;
        }
        else
        {
            vec[ConnectSIndex] = ConnectEIndex;
        }
    }

}

int main()
{
    int N, M;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    vec.resize(N + 1);
    for (int i = 0; i < N; ++i)
    {
        vec[i + 1] = i + 1;
    }

    for (int i = 0; i < M; ++i)
    {
        int b, s, e;
        std::cin >> b >> s >> e;

        if (b == 0)
        {
            Union(s, e);
        }
        else
        {
            if (Find(s, e))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }

    return 0;
}

