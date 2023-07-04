// MoreHot.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int answer = 0;

    for (int i = 0; i < scoville.size(); ++i)
        pq.push((int)scoville[i]);

    while (pq.size() != 1 && pq.top() < K)
    {
        int Scoville1 = pq.top();
        pq.pop();
        int Scoville2 = pq.top();
        pq.pop();

        int NewScoville = Scoville1 + (Scoville2 * 2);

        pq.push(NewScoville);

        answer++;
    }

    if (pq.top() < (int)K)
        return -1;

    else
        return answer;
}


int main()
{
    std::cout << solution({1, 2, 3, 9, 10, 12},	7);
}