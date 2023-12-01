// 1744.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

int N;

int main()
{
    std::cin >> N;
    std::priority_queue<int, std::vector<int>, std::less<int>> pqPlus;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqMinus;

    bool ZeroCheck = false;
    for (size_t i = 0; i < N; i++)
    {
        int Numb;
        std::cin >> Numb;

        if (Numb <= 0)
        {
            if (Numb == 0)
                ZeroCheck = true;
            pqMinus.push(Numb);
        }
        else 
            pqPlus.push(Numb);
    }
    
    int Sum = 0;

    while (!pqMinus.empty() && pqMinus.size() >= 2)
    {
        int Num1 = pqMinus.top();
        pqMinus.pop();
        int Num2 = pqMinus.top();
        pqMinus.pop();
        Sum += (Num2 * Num1);
    }
    
    while (!pqPlus.empty() && pqPlus.size() >= 2)
    {
        int Num1 = pqPlus.top();
        pqPlus.pop();
        int Num2 = pqPlus.top();
        pqPlus.pop();

        Sum += std::max(Num1 + Num2, Num1 * Num2);
    }

    if (!pqMinus.empty())
    {
        int MinusNum = pqMinus.top();

        if (ZeroCheck == false)
        {
            Sum += MinusNum;
        }
    }
    if (!pqPlus.empty())
    {
        Sum += pqPlus.top();
    }

    std::cout << Sum;

    return 0;
}