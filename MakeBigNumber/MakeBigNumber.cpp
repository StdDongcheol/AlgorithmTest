// MakeBigNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k)
{
    stack<char> stkNumb;
    string answer = "";

    int Count = 0;
    int index = number.size();

    for (int i = 0; i < number.size(); ++i)
    {
        char CurData = number[i];

        while (!stkNumb.empty() && k > Count)
        {
            char stkData = stkNumb.top();

            if (CurData > stkData)
            {
                stkNumb.pop();
                ++Count;
            }

            else
                break;
        }

        stkNumb.push(CurData);
    }

    for (int i = stkNumb.size(); i > number.size() - k; --i)
    {
        stkNumb.pop();
    }
    
    while (!stkNumb.empty())
    {
        char stkData = stkNumb.top();
        stkNumb.pop();
        answer += stkData ;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution("4177252841", 4);

    return 0;
}
