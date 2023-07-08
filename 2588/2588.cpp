// 2588.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

int main()
{
    int A, B, srcB;
    std::cin >> A >> B;
    srcB = B;
    for (int i = 0; i < 3; ++i)
    {
        int Numb = B % 10;
        B /= 10;

        std::cout << A * Numb << '\n';
    }

    std::cout << A * srcB << '\n';
}