#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ms = 0;

struct compare
{
    bool operator()(pair<int, int>& l, pair<int, int>& r)
    {
        return l.second > r.second;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int idx = 0;
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    std::sort(jobs.begin(), jobs.end());

    while (idx < jobs.size() || !pq.empty())
    {
        if (idx < jobs.size() && jobs[idx][0] <= ms)
        {
            pq.push(make_pair(jobs[idx][0], jobs[idx][1]));
            ++idx;
            continue;
        }

        if (!pq.empty())
        {
            ms += pq.top().second;
            answer += (ms - pq.top().first);
            pq.pop();
        }
        else
            ms = jobs[idx][0];
    }

    return floor(answer / jobs.size());
}