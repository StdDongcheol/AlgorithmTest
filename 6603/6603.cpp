// 6603.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int NumbArr[13];
bool CheckArr[13];
std::vector<std::vector<int>> vec;

void Check(int _Next, int _Count, int _Max, int _k)
{
    if (_Count == _Max)
    {
        std::vector<int> _vec;

        for (int i = 0; i < _k; ++i)
        {
            if (!CheckArr[i])
                _vec.push_back(NumbArr[i]);
        }
        vec.push_back(_vec);

        return;
    }

    for (int i = _Next; i < _k; ++i)
    {
        if (!CheckArr[i])
        {
            CheckArr[i] = true;
            Check(i + 1, _Count + 1, _Max, _k);
            CheckArr[i] = false;
        }
    }

    return;
}

int main()
{
    int k = 0;
    while (std::cin >> k)
    {
        if (k == 0)
            break;

        for (int i = 0; i < k; ++i)
            std::cin >> NumbArr[i];

        Check(0, 0, k - 6, k);

        std::sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size(); ++i)
        {
            for (int n : vec[i])
            {
                std::cout << n << ' ';
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        vec.clear();
    }

    return 0;
}