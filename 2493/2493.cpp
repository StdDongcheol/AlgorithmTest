// 2493.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::vector<int> vec;
    std::vector<int> vecRes;
    std::stack<std::pair<int, int>> stk;

    int N;
    std::cin >> N;
    vecRes.resize(N + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        int Numb;
        std::cin >> Numb;
        vec.push_back(Numb);
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        stk.push({ vec[i], i + 1 });
    }

    std::stack<std::pair<int, int>> TopStk;

    while (!stk.empty())
    {
        int TopNumb = stk.top().first;
        int TopIndex = stk.top().second;
        stk.pop();

        while (!TopStk.empty() && TopNumb > TopStk.top().first)
        {
            vecRes[TopStk.top().second] = TopIndex;
            TopStk.pop();
        }
    
        TopStk.push({ TopNumb, TopIndex });
    }

    for (int i = 1; i < vecRes.size(); ++i)
    {
        std::cout << vecRes[i] << " ";
    }

    return 0;
}
