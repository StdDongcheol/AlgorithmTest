// PhoneNumbList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book)
{
    bool answer = true;
    std::unordered_map<string, int> um;
    

    for (int i = 0; i < phone_book.size(); ++i)
        um.insert(std::make_pair(phone_book[i], 1));

    for (int i = 0; i < phone_book.size(); ++i)
    {
        std::string str = "";

        for (int j = 0; j < phone_book[i].size(); ++j)
        {
            str += phone_book[i][j];

            auto iter = um.find(str);
            
            if (iter != um.end() && str != phone_book[i])
                return false;
        }
    }

    return true;
}

int main()
{
    std::cout << solution({"119", "97674223", "1195524421" });
}

