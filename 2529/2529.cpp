// 2529.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

char arrChar[10];
bool arrInt[10];

std::vector<std::string> vec;

// ex) _N = 2
void Check(int _count, int _N, std::string& _str)
{
    if (_count == _N)
    {
        bool Check = true;
        for (int i = 0; i < _N - 1; ++i)
        {
            switch (arrChar[i])
            {
                case '<':
                {
                    if (_str[i] > _str[i + 1])
                        Check = false;
                    break;
                }

                case '>':
                {
                    if (_str[i] < _str[i + 1])
                        Check = false;
                    break;
                }
            }
            if (!Check)
                return;
        }

        vec.push_back(_str);
        return;
    }

    for (int j = 0; j < 10; ++j)
    {
        if (!arrInt[j])
        {
            _str += std::to_string(j);
            arrInt[j] = true;
            Check(_count + 1, _N, _str);
            arrInt[j] = false;
            _str.pop_back();
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> arrChar[i];

    std::string str;
    Check(0, N + 1, str);

    std::sort(vec.begin(), vec.end());
    
    std::cout << *std::max_element(vec.begin(), vec.end()) << '\n';;
    std::cout << *std::min_element(vec.begin(), vec.end());
}
