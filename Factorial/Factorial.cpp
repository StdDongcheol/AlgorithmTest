// Factorial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Factorial(int N, int Numb)
{
    if (N == 1)
        return Numb;

    return Factorial(N - 1, N * Numb);
}

int FactorialTail(int N)
{
    return Factorial(N - 1, N);
}

int main()
{
    std::cout << FactorialTail(4);
}
