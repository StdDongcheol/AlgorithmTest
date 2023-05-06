// 1202.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
    int N, K;
    long long Result = 0;
    std::priority_queue<long long> q;
    std::vector<long long> vecPacks;
    std::vector<std::pair<long long, long long>> vecGems;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    std::cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        int M, V;
        std::cin >> M >> V;
        vecGems.push_back(std::make_pair(M, V));
    }

    for (int i = 0; i < K; ++i)
    {
        int C;
        std::cin >> C;

        vecPacks.push_back(C);
    }

    std::sort(vecGems.begin(), vecGems.end());
    std::sort(vecPacks.begin(), vecPacks.end());

    int GemIndex = 0;

    // 가방갯수만큼 반복
    for (int i = 0; i < K; ++i)
    {
        // 보석 갯수만큼 반복 및 현재 가방이 보석을 담을수 있는 무게라면
        while (GemIndex < N && vecGems[GemIndex].first <= vecPacks[i])
        {
            // 우선순위 큐에 보석을 담음
            q.push(vecGems[GemIndex].second);
            ++GemIndex;
        }

        // 현재 가방에 담을 수 있는 가장 높은 보석가치를 갱신
        if (!q.empty())
        {
            Result += q.top();
            q.pop();
        }
    }

    std::cout << Result;

    return 0;
}