// PowerOfNightWork.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;

    long long answer = 0;

    for (int i : works)
        pq.push(i);

    while (n > 0 && !pq.empty())
    {
        int Numb = pq.top();
        pq.pop();

        --Numb;
        --n;

        if (Numb == 0)
            continue;
        else
            pq.push(Numb);
    }

    while (!pq.empty())
    {
        int Numb = pq.top();
        pq.pop();

        answer += pow(Numb, 2);
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}