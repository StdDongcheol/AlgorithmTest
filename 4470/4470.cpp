// 4470.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    int N;
    std::vector<std::string> vecStr;

    std::cin >> N;
    std::cin.ignore();

    vecStr.resize(N);

    for (int i = 0; i < N; ++i)
    {
        std::getline(std::cin, vecStr[i]);
        std::cin.clear();
    }

    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << ". " + vecStr[i] << "\n";
    }

    return 0;
}