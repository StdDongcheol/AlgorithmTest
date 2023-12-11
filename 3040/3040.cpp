// 3040.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int arrN[9];
bool arrCheck[9];
std::vector<int> vecResult;
bool Check = false;

void DFS(int _CurCount, int _sum, std::vector<int> _vec)
{
    if (_CurCount == 7)
    {
        if (_sum == 100 && Check == false)
        {
            Check = true;
            vecResult = _vec;
            return;
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        if (arrCheck[i] == false)
        {
            arrCheck[i] = true;
            _vec.push_back(arrN[i]);
            DFS(_CurCount + 1, _sum + arrN[i], _vec);
            _vec.pop_back();
            arrCheck[i] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        std::cin >> arrN[i];
    }
    std::vector<int> vec;

    DFS(0, 0, vec);
    
    for (int N : vecResult)
        std::cout << N << '\n';


    return 0;
}
