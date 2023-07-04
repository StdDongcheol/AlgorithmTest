// TranslateWord.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool arrCheck[50];
int Result = 9999;

void DFS(std::string strSrc, std::string strTarget, 
    int _Count, std::vector<std::string>& vecWords)
{
    if (strSrc == strTarget)
    {
        if (_Count < Result)
            Result = _Count;
        return;
    }

    for (int i = 0; i < vecWords.size(); ++i)
    {
        if (arrCheck[i])
            continue;

        std::string str = vecWords[i];
        int diffCount = 0;

        for (int j = 0; j < str.length(); ++j)
        {
            if (strSrc[j] != str[j])
                ++diffCount;
        }

        if (diffCount == 1)
        {
            arrCheck[i] = true;
            DFS(str, strTarget, _Count + 1, vecWords);
            arrCheck[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    DFS(begin, target, 0, words);
    
    if (Result == 9999)
        return 0;

    else
    {
        answer = Result;
        return answer;
    }
}

int main()
{
    std::cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}
