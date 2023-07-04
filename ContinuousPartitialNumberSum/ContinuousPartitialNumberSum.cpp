// ContinuousPartitialNumberSum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    vector<pair<int, int>> vec;

    int Start = 0;
    int End = 0;

    int Sum = 0;
    Sum = sequence[End];
    while (End < sequence.size())
    {
        if (Sum == k)
        {
            vec.push_back(make_pair(Start, End));

            Sum -= sequence[Start];
            ++Start;
            ++End;
            Sum += sequence[End];
        }
        else if (Sum > k)
        {
            Sum -= sequence[Start];
            ++Start;
        }
        else if (Sum < k)
        {
            ++End;
            Sum += sequence[End];
        }
    }

    int min = 999999999;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i].second - vec[i].first < min)
        {
            min = vec[i].second - vec[i].first;
            answer.clear();
            answer.push_back(vec[i].first);
            answer.push_back(vec[i].second);
        }
    }

    return answer;
}