// 1516.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

int main()
{
    int N;
    std::vector<int> vecDegree;
    std::vector<int> vecBuildTime;
    std::vector<int> vecBuildTimeAcc;
    std::queue<int> queue;
    std::vector<std::vector<int>> vecBuild;

    std::cin >> N;
    vecDegree.resize(N + 1);
    vecBuild.resize(N + 1);
    vecBuildTime.resize(N + 1);
    vecBuildTimeAcc.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        int Time;
        int Input = 0;

        std::cin >> Time;
        vecBuildTime[i] = Time;

        while (true)
        {
            std::cin >> Input;
            if (Input == -1)
                break;

            vecBuild[Input].push_back(i);
            ++vecDegree[i];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (vecDegree[i] == 0)
            queue.push(i);
    }

    while (!queue.empty())
    {
        int Index = queue.front();
        queue.pop();

        for (int i = 0; i < vecBuild[Index].size(); ++i)
        {
            int NextNode = vecBuild[Index][i];
            --vecDegree[NextNode];

            // 노드 추가
            if (vecDegree[NextNode] == 0)
                queue.push(NextNode);

            vecBuildTimeAcc[NextNode] = fmax(vecBuildTimeAcc[NextNode], vecBuildTimeAcc[Index] + vecBuildTime[Index]);
        }
    }

    for (int i = 1; i <= N; ++i)
        std::cout << vecBuildTimeAcc[i] + vecBuildTime[i] << "\n";

    return 0;
}
