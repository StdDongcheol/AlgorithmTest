﻿// 18108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int Year;

    std::cin >> Year;
    int CovertedYear = Year - 543;

    std::cout << CovertedYear;

    return 0;
}