// MaxValueMinValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s)
{
    string answer = "";
    string Str = "";
    std::deque<int> dq;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
        {
            Str += s[i];
        }

        else
        {
            dq.push_back(std::stoi(Str));
            Str = "";
        }

    }

    std::sort(dq.begin(), dq.end());

    answer += to_string(dq.front()) + " " + to_string(dq.back());

    return answer;
}


int main()
{
    solution("-1 -2 3 -4");
}
