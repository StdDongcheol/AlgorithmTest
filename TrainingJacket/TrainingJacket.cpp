// TrainingJacket.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>

using namespace std;

int solution(int N, vector<int> lost, vector<int> reserve)
{
    int answer = 0;

    std::vector<int> vecStudent;

    vecStudent.resize(N + 1, 1);

    for (int i = 0; i < lost.size(); ++i)
    {
        int lostStudent = lost[i];
        vecStudent[lostStudent] -= 1;
    }

    for (int i = 0; i < reserve.size(); ++i)
    {
        int reserveStudent = reserve[i];
        vecStudent[reserveStudent] += 1;
    }

    for (int i = 0; i < reserve.size(); ++i)
    {
        int reserveStudent = reserve[i];

        if (vecStudent[reserveStudent] <= 1)
            continue;

        if (reserveStudent >= 0 && vecStudent[reserveStudent - 1] == 0)
            vecStudent[reserveStudent - 1] += 1;

        else if (reserveStudent <= N && vecStudent[reserveStudent + 1] == 0)
            vecStudent[reserveStudent + 1] += 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (vecStudent[i] >= 1)
            ++answer;
    }

    return answer;
}

int main()
{
    solution(5, {3}, {});

    return 1;
}