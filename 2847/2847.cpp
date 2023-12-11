// 2847.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arrN[100];
int N;

int main()
{
    std::cin >> N;
    
    for (int i = 0; i < N; ++i)
        std::cin >> arrN[i];
    
    int Count = 0;
    for (int i = N - 2; i >= 0; --i)
    {
        while (arrN[i] >= arrN[i + 1])
        {
            arrN[i]--;
            Count++;
        }
    }

    std::cout << Count;
    
    return 0;
}

