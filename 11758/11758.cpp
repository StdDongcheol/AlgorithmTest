// 11758.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

int main()
{
    int X1, Y1; 
    int X2, Y2; 
    int X3, Y3;

    std::cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    int Px1, Py1;
    int Px2, Py2;
    Px1 = X2 - X1;
    Py1 = Y2 - Y1;
    Px2 = X3 - X2;
    Py2 = Y3 - Y2;

    int Value = (Px1 * Py2) - (Px2 * Py1);

    if (Value > 0)
    {
        std::cout << 1;
    }
    else if (Value < 0)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << 0;
    }

    return 0;
}
