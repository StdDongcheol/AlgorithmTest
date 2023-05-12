#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;
    int temp = 0;


    std::sort(routes.begin(), routes.end());
    temp = routes[0][1];

    for (int i = 1; i < routes.size(); ++i)
    {
        if (temp < routes[i][0])
        {
            ++answer;
            temp = routes[i][1];
        }

        if (routes[i][1] <= temp)
            temp = routes[i][1];
    }

    return answer;
}

int main()
{
    solution({ {-20,15}, {-14, -5}, {-18, -13}, {-5, -3} });
    return 0;
}