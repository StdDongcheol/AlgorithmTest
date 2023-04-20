#include <string>
#include <vector>

using namespace std;

int TargetNumb;
int answers = 0;

void DFS(vector<int>& vecNum, int Sum, int Count)
{
    if (Count == vecNum.size())
    {
        if (TargetNumb == Sum)
            ++answers;

        return;
    }

    int AddSum = Sum + vecNum[Count];
    int SubSum = Sum - vecNum[Count];

    DFS(vecNum, AddSum, Count + 1);
    DFS(vecNum, SubSum, Count + 1);
}

int solution(vector<int> numbers, int target)
{
    TargetNumb = target;

    DFS(numbers, 0, 0);

    return answers;
}

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    solution(vec, 3);

    return 0;
}