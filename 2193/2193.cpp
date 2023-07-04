// 2193.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

long long arr[91][2] = {};

std::vector<std::vector<std::string>> strvec;

int main()
{
    std::vector<std::string> vec;
    int N;
    std::cin >> N;
    arr[1][0] = 0;
    arr[1][1] = 1;


    for (int i = 2; i <= N; ++i)
    {
        arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
        arr[i][1] = arr[i - 1][0];
    }

    std::cout << arr[N][0] + arr[N][1];

    return 0;
}
