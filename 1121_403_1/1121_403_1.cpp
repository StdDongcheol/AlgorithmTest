// 1121_403_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<int> vecDP;

int main()
{
    int n;
    std::cin >> n;

    vecDP.resize(333333333);
    vecDP[0] = -1;
    vecDP[1] = -1;
    vecDP[2] = -1;
    vecDP[3] = 1;
    vecDP[4] = -1;
    vecDP[5] = 1;
    vecDP[6] = 2;

    for (int i = 7; i < vecDP.size(); ++i)
    {
        __int64 CurBox = i - 3;
        if(CurBox )
        vecDP[i] = std::min(vecDP[i - 3] + vecDP[i - 5]);
    }


    return 0;
}
