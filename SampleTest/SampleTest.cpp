#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int a[5] = { 1,2,3,4,5 };
int b[8] = { 2,1,2,3,2,4,2,5 };
int c[10] = { 3,3,1,1,2,2,4,4,5,5 };

int Supoja(vector<int> answers, int Number)
{
    int Count = 0;
    int Index = 0;
    switch (Number)
    {
    case 0:
    {
        for (int i = 0; i < answers.size(); ++i)
        {
            Index = i % 5;

            if (answers[i] == a[Index])
                ++Count;
        }
        break;
    }
    case 1:
    {
        for (int i = 0; i < answers.size(); ++i)
        {
            Index = i % 8;

            if (answers[i] == b[Index])
                ++Count;
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < answers.size(); ++i)
        {
            Index = i % 10;

            if (answers[i] == c[Index])
                ++Count;
        }
        break;
    }
    }

    return Count;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<pair<int, int>> vecCounts;

    for (int i = 0; i < 3; ++i)
    {
        vecCounts.push_back(make_pair(Supoja(answers, i), i));
    }

    sort(vecCounts.begin(), vecCounts.end());

    int Top = vecCounts[vecCounts.size() - 1].first;

    if (Top > 0)
    {
        answer.push_back(vecCounts[vecCounts.size() - 1].second);
        for (int i = vecCounts.size() - 1; i > 0; --i)
        {
            if (Top == vecCounts[i - 1].first)
            {
                answer.push_back(vecCounts[i - 1].second);
            }
        }
    }

    return answer;
}