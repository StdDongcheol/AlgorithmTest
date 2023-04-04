#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

struct MyCompare
{
    bool operator()(int l, int r)
    {
        if (abs(l) == abs(r))
            return l > r;
        else
            return abs(l) > abs(r);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    std::vector<int> answer;
    std::priority_queue<int, std::vector<int>, MyCompare> pQue;
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int Number;
        std::cin >> Number;

        if (Number != 0)
        {
            pQue.push(Number);
        }

        else
        {
            if (pQue.empty())
                answer.push_back(0);

            else
            {
                answer.push_back(pQue.top());
                pQue.pop();
            }
        }
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        std::cout << answer[i] << "\n";
    }

    return 0;
}