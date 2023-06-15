// 9498.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

int main()
{
    int A;
    std::cin >> A;

    if (A <= 100 && A >= 90)
        std::cout << "A";
    else if (A <= 89 && A >= 80)
        std::cout << "B";
    else if (A <= 79 && A >= 70)
        std::cout << "C";
    else if (A <= 69 && A >= 60)
        std::cout << "D";
    else
        std::cout << "F";

}