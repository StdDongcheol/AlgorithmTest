// 1193.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int X = 0;
    std::cin >> X;

    int Row = 1;
    while (true)
    {
        if ((Row * (Row + 1)) / 2 >= X)
            break;

        ++Row;
    }

    int Count = ((Row - 1) * Row) / 2;  // 이전 Row까지의 총 숫자 갯수
    int i = X - Count;  // 현위치 X - 이전 Row 까지의 숫자 갯수
    int j = Row + 1 - i;

    if (Row % 2 == 0)
        std::cout << i << "/" << j;


    else
        std::cout << j << "/" << i;

    return 0;
}
