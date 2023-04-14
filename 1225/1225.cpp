// 1225.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
    std::string A;
    std::string B;
    long long Sum = 0;

    std::cin >> A >> B;
    
    for (int i = 0; i < A.length(); ++i)
    {
        for (int j = 0; j < B.length(); ++j)
        {   
            int ANumb = (int)A[i] - 48;
            int BNumb = (int)B[j] - 48;

            Sum += (ANumb * BNumb);
        }
    }

    std::cout << Sum;
}
