// 1676.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

typedef unsigned long long ull;

ull Fact(ull _x, ull _result)
{
    if (_x == 1)
        return _result;
    else
        return Fact(_x - 1, _result * _x);
}

int main()
{
    int N;
    std::cin >> N;

    std::cout << Fact((ull)N, 1);

    return 0;
}
