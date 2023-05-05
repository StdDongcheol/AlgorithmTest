
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> vecCheck = {};
std::vector<int> vecCount = {};

int DFS(int _Index, int _Count, int _Energy, std::vector<std::vector<int>> _dungeons)
{
    if (_dungeons[_Index][0] > _Energy)
    {
        return _Count;
    }
    
    vecCheck[_Index] = true;
    _Energy -= _dungeons[_Index][1];
    ++_Count;
        
    for (int i = 0; i < _dungeons.size(); ++i)
    {
        if (!vecCheck[i])
            _Count = DFS(i, _Count, _Energy, _dungeons);
    }

    vecCount.push_back(_Count);

    vecCheck[_Index] = false;
    --_Count;

    return _Count;
}

int solution(int _k, std::vector<std::vector<int>> _dungeons)
{
    int CurEnergy = _k;
    int Count = 0;

    vecCheck.resize(_dungeons.size(), false);
    
    for (int i = 0; i < _dungeons.size(); ++i)
        DFS(i, 0, CurEnergy, _dungeons);

    Count = *std::max_element(vecCount.begin(), vecCount.end());

    return Count;
}
/// <summary>
/// 처음에는 던전찾는 방식은 터득했는데,
/// 던전을 탐색하는 방식을 단순히 정렬해서 선형탐색만하는게 아니고
/// 완전탐색이었던것이다.
/// 
/// 이 문제의 주제를 잠시 잊고있엇으나, 완탐문제기 때문에
/// DFS로 던전을 모두 순회해봐야 한다.
/// </summary>

int main()
{
    int K = 80;
    std::vector<std::vector<int>> vec = { {80, 20}, { 50, 40 }, { 30, 10 } };

    std::cout << solution(K, vec);
    return 0;
}

