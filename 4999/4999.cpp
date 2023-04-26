// 4999.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
    std::string strDoc;
    std::string strJae;

    std::cin >> strDoc;
    std::cin >> strJae;

    if (strDoc.size() <= strJae.size())
        std::cout << "go";
    else
        std::cout << "no";

    return 0;
}
