// IsValid.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


bool IsValid(int iValid)
{
    int CheckArr[10] = {};
    bool Check = true;

    while (iValid > 0)
    {
        int Numb = iValid % 10;
        iValid /= 10;
        ++CheckArr[Numb];
    }

    for (int i = 1; i <= 9; ++i)
    {
        if (CheckArr[i] <= 0)
        {
            Check = false;
            break;
        }
    }
    
    return Check;
}

int main()
{
    std::cout << IsValid(100000000);

    return 0;
}