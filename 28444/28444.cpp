// 28444.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int H, I, A, R, C;

    std::cin >> H >> I >> A >> R >> C;

    std::cout << (H * I) - (A * R * C);

    return 0;
}