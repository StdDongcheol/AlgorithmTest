
// 10986.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N, M = 0;
    long Answer = 0;
    
    std::vector<long> Numb;
    std::vector<long> Sum;
    std::vector<long> Modulo;

    std::cin >> N >> M;
    
    Numb.resize(N + 1, 0);
    Sum.resize(N + 1, 0);
    Modulo.resize(M + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Numb[i];

        Sum[i] = Sum[i - 1] + Numb[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        Sum[i] %= M;

        if (Sum[i] == 0)
            ++Answer;

        ++Modulo[Sum[i]];
    }

    for (int i = 0; i < Modulo.size(); ++i)
    {
        if (Modulo[i] != 0)
            Answer += (Modulo[i] * (Modulo[i] - 1) / 2);
    }

    std::cout << Answer << "\n";

    return 0;
}
