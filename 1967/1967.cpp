// 1967.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> vecVisit;
std::vector<int> vecDepth;
std::vector<std::vector<int>> vecCheck;

void Inorder(int _Start, int _End, int _CurLevel, int _MaxLevel)
{
    if (_CurLevel >= _MaxLevel)
        return;

    if (_Start == _End)
    {
        vecCheck[_CurLevel].push_back(vecVisit[_Start]);
        return;
    }
    int Center = (_Start + _End) / 2;

    vecCheck[_CurLevel].push_back(vecVisit[Center]);

	Inorder(_Start, Center - 1, _CurLevel + 1, _MaxLevel);
	Inorder(Center + 1, _End, _CurLevel + 1, _MaxLevel);
}


int main()
{
    int N;
    std::cin >> N;
    int Size = pow(2, N) - 1;

    vecDepth.resize(Size + 1);
    vecCheck.resize(Size + 1);
    vecVisit.resize(Size + 1);

    for (int i = 0; i < Size; ++i)
    {
        std::cin >> vecVisit[i];
    }

    Inorder(0, vecCheck.size(), 1, N);

    for (int i = 0; i < vecCheck.size(); ++i)
    {
        for (int j = 0; j < vecCheck[i].size(); ++j)
        {
            std::cout << vecCheck[i][j] << " ";
        }

        std::cout << '\n';
    }
}