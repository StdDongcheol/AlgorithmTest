// FindPrimeNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<int> vecResult;

int solution(std::string numbers) 
{
    int answer = 0;
    std::vector<char> vecNumb;

    for (int i = 0; i < numbers.size(); ++i)
    {
        vecNumb.push_back(numbers[i]);
    }

    std::sort(vecNumb.begin(), vecNumb.end());

    do
    {
        std::string strTemp = "";
        
        for (int i = 0; i < vecNumb.size(); ++i)
        {
            strTemp.push_back(vecNumb[i]);
            vecResult.push_back(std::stoi(strTemp));
        }
    
    } while (std::next_permutation(vecNumb.begin(), vecNumb.end()));

    std::vector<int> TempVEc = vecResult;
    std::sort(vecResult.begin(), vecResult.end());
    std::sort(TempVEc.begin(), TempVEc.end());

    std::unique(vecResult.begin(), vecResult.end());


    vecResult.erase(std::unique(vecResult.begin(), vecResult.end()), vecResult.end());

    for (int i = 0; i < vecResult.size(); ++i)
    {
        int Numb = vecResult[i];
        
        bool Check = true;

        if (Numb == 0 || Numb == 1)
            continue;

        for (int i = 2; i <= sqrt(Numb); ++i)
        {
            if (Numb % i == 0)
            {
                Check = false;
                break;
            }
        }

        if (Check)
            ++answer;
    }

    return answer;
}

int main()
{
    solution("011");
}
