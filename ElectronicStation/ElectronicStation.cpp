// ElectronicStation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<bool> vecCheck = {};
std::vector<std::vector<int>> vecWires = {};
int CutV1;
int CutV2;

int DFS(int _index, int _count)
{
    vecCheck[_index] = true;

    for (int i = 1; i <= vecWires[_index].size(); ++i)
    {
        int NextV = vecWires[_index][i - 1];

        if (vecCheck[NextV])
            continue;

        if ((_index == CutV1 && NextV == CutV2) ||
            (_index == CutV2 && NextV == CutV1))
            continue;

        _count = DFS(NextV, _count + 1);
    }

    return _count;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 9999;

    vecCheck.resize(n + 1, false);
    vecWires.resize(n + 1);

    for (int i = 0; i < wires.size(); ++i)
    {
        int v1 = wires[i][0];
        int v2 = wires[i][1];

        vecWires[v1].push_back(v2);
        vecWires[v2].push_back(v1);
    }


    int Count1 = -1;
    int Count2 = -1;

    for (int i = 0; i < wires.size(); ++i)
    {
        CutV1 = wires[i][0];
        CutV2 = wires[i][1];

        for (int j = 1; j <= n; ++j)
        {
            if (!vecCheck[j] && Count1 == -1)
                Count1 = DFS(j, 1);
            else if (!vecCheck[j] && Count2 == -1)
                Count2 = DFS(j, 1);
        }

        if (answer > abs(Count1 - Count2))
            answer = abs(Count1 - Count2);

        std::fill(vecCheck.begin(), vecCheck.begin() + n + 1, false);
        Count1 = -1;
        Count2 = -1;
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";

    solution(4, {{1, 2
}, { 2, 3
}, { 3, 4 }});
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
