// 28691.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    char c;
    std::cin >> c;

    switch (c)
    {
    case 'M':
        std::cout << "MatKor";
        break;
    case 'W':
        std::cout << "WiCys";
        break;
    case 'C':
        std::cout << "CyKor";
        break;
    case 'A':
        std::cout << "AlKor";
        break;
    case '$':
        std::cout << "$clear";
        break;
    }

    return 0;
}