// ThreeMen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void Find(int count, int index, int sum, vector<int>& number)
{
    if (count == 3)
    {
        if (sum == 0)
            answer++;
        
        return;
    }

    for (int i = index; i < number.size(); i++)
        Find(count + 1, i + 1, sum + number[i], number);
}

int solution(vector<int> number)
{
    vector<int> vec;
    for (int i = 0; i < number.size(); i++)
    {
        Find(1, i + 1, number[i], number);
    }
    std::cout << answer; 
    return answer;
}

int main()
{
    solution({-2, 3, 0, 2, -5});
}