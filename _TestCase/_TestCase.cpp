#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 바이트패딩

// 패딩기준은 항상 제일 큰 타입의 사이즈를 따라간다.
// "가상함수포인터" 도 예외없이 제일 큰타입의 사이즈로 동일하게 따라감.

// 32bit나 64bit나 가상함수 "포인터"기 때문에, 사이즈 역시 동일하게 따라감.

// 그러나 타입 기준이 최우선사항임.
// 1번 우선순위 제일큰타입(ex: doubleType)
// 2번 우선순위 운영체제 bit

//class A
//{
//    int i;          // 4
//    int ii;         // 4
//    double d;       // 8
//    int _3c;         // 1
//    char _c;         // 1
//    char _2c;         // 1
//    //char c;         // 1
//    //char cc;         // 1
//    //char ccc;         // 1
//    //char cccc;         // 1
//    //int iii;           // 4
//    
//    virtual void pirnt();   // 8
//};
//
//class B
//{
//    int* m_iInt;
//
//    virtual void pirnt();
//};

// 10826.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


unsigned long long arr[10001] = { 0, 1 };

int main()
{
    int  N;

    std::cin >> N;
    int Count = 1;

    if (N == 0)
    {
        std::cout << 0;
        return 0;
    }

    while (N != Count)
    {
        arr[Count + 1] = arr[Count] + arr[Count - 1];
        ++Count;
    }

    std::cout << arr[Count];

    return 0;
}
