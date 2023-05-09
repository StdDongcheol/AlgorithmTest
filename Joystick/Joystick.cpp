// Joystick.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
std::vector<int> vecCount;
std::vector<bool> vecCheck;
int ACount = 0;

//  JEROEN
void DFS(int _index, int _length, int FindCount, int _count, std::string& name)
{
    if (_length == FindCount)
    {
        vecCount.push_back(_count - 1);
        return;
    }
    std::priority_queue<int> q;

    if (_index < 0)
        _index = name.length() - 1;

    else if (_index >= name.length())
        _index = 0;

    if (name[_index] != 'A' && !vecCheck[_index])
    {
        int NameCount = (int)(name[_index] - 'A');
        int ReverseCount = 26 - NameCount;

        if (ReverseCount >= NameCount)
            _count += NameCount;
        else
            _count += ReverseCount;

        vecCheck[_index] = true;
        ++FindCount;
    }

    DFS(_index + 1, _length, FindCount, _count + 1, name);
    DFS(_index - 1, _length, FindCount, _count + 1, name);
}

int solution(string name)
{
    int answer = 0;

    vecCheck.resize(name.length(), false);

    for (int i = 0; i < name.length(); ++i)
    {
        if (name[i] == 'A')
            ++ACount;
    }

    if (ACount == name.length())
        return 0;

    DFS(0, (int)name.length() - ACount, 0, 0, name);

    std::sort(vecCount.begin(), vecCount.end());
    answer = vecCount[0];
    return answer;
}

int main()
{
    solution("JEROEN");
}
