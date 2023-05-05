// MoumDictionary.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char CharWord[5] = { 'A', 'E', 'I', 'O', 'U' };
int WordCount = 0;

int DFS(string ToWord, string word, int Count)
{
    if (ToWord == word)
    {
        WordCount = Count;
        return Count;
    }

    if (ToWord.length() > 5)
        return Count;

    ++Count;

    for (int i = 0; i < 5; ++i)
    {
        Count = DFS(ToWord + CharWord[i], word, Count);
    }

    return Count;
}

int solution(string word)
{
    int answer = 0;
    string FindWord = "";
    DFS(FindWord, word, 0);

    answer = WordCount;

    return answer;
}


int main()
{
    solution("I");

    return 0;
}