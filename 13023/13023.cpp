// 13023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<std::vector<int>>   vecRelation;
std::vector<bool>  vecCheck;
bool Check = false;

void DFS(int index, int depth)
{
    if (depth >= 5)
    {
        Check = true;
        return;
    }

    vecCheck[index] = true;

    for (int i = 0; i < vecRelation[index].size(); ++i)
    {
        int Visit = vecRelation[index][i];

        if (!vecCheck[Visit])
            DFS(Visit, depth + 1);

        if (Check)
            return;
    }

    vecCheck[index] = false;
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    vecRelation.resize(N);
    vecCheck.resize(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        vecRelation[a].push_back(b);
        vecRelation[b].push_back(a);
    }

    for (int i = 0; i < N; ++i)
    {
        DFS(i, 1);
    }

    if (Check)
        std::cout << 1;
    else
        std::cout << 0;

    return 0;
}
