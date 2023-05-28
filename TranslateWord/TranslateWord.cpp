// TranslateWord.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string srcBegin;
string srcTarget;
vector<int> vecCount;
vector<bool> vecCheck;
int MoveCount = 0;

int DFS(string curStr, string targetStr, vector<string>& vecWords)
{
    size_t strSize = curStr.length();
    int count = 0;

    if (curStr == srcTarget)
    {
        vecCount.push_back(MoveCount);
        return 0;
    }

    for (int i = 0; i < strSize; ++i)
    {
        if (curStr[i] != targetStr[i])
            ++count;
    }

    if (count >= 2)
        return 0;

    for (int i = 0; i < vecWords.size(); ++i)
    {
        count = 0;
        int index = 0;

        for (int j = 0; j < vecWords[i].length(); ++j)
        {
            if (vecWords[i][j] != targetStr[j])
            {
                ++count;
                index = j;
            }
        }

        if (count == 1 && vecWords[i][index] != targetStr[index])
        {
            if (!vecCheck[i])
            {
                ++MoveCount;
                vecCheck[i] = true;
                DFS(targetStr, vecWords[i], vecWords);
                vecCheck[i] = false;
                --MoveCount;
            }
        }
    }

    return MoveCount;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    vecCheck.resize(words.size(), false);
    srcBegin = begin;
    srcTarget = target;

    for (int i = 0; i < words.size(); ++i)
    {
        DFS(begin, words[i], words);
        std::fill(vecCheck.begin(), vecCheck.end(), false);
    }
    
    if (vecCount.empty())
        return 0;

    return *std::min_element(vecCount.begin(), vecCount.end());
}

int main()
{
    std::cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}
