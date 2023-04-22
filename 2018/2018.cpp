// 2018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    int Count = 1;

    int Start = 1, End = 1;

    std::cin >> N;
    
    while (End != N)
    {
        int Sum = 0;

        for (int i = Start; i <= End; ++i)
        {
            Sum += i;
        }

        if (Sum == N)
            ++Count;
        
        if (Sum < N)
            ++End;

        else if (Sum >= N)
            ++Start;
    
    }
    
    std::cout << Count;
}
