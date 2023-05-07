
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int start = 0;
    int end = people.size() - 1;

    std::sort(people.begin(), people.end());

    // 단순한 two-pointer 탐색.
    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
        {
            ++start;
            --end;
        }
        else
            --end;

        ++answer;
    }

    return answer;
}

int main()
{
    solution({70, 80, 50, 50}, 100);
}
