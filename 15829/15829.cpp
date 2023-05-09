// 15829.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <map>
#include <cmath>

long long r = 1;
int M = 1234567891;

long long hashing(std::string _str, int N)
{
    long long HashValue = 0;

    for (int i = 0; i < N; ++i)
    {
        long long iValue = (long long)(_str[i] - 'a' + 1);

        // 예) ('c' * r^i) % M <<< HashValue
        HashValue += (iValue * r) % M;

        // 예) 모듈로연산으로 HashValue 감소
        HashValue %= M;
        
        // 예) 모듈로연산으로 r값 감소
        r = (r * 31) % M;
    }

    return HashValue;
}

int main()
{
    int N = 0;
    std::string str;

    std::cin >> N;
    std::cin >> str;

    std::cout << hashing(str, N);

    return 0;
}

