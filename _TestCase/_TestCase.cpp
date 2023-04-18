// _TestCase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>


// 포인터 변수의 경우는 ->나 *를 써서 접근해야 하지만,
// 레퍼런스 변수는 일반 변수처럼 사용할수 있지.
void Func(int& str)
{
    int* a = new int;

    return;
}

void Func1(int* str)
{
    int* a = new int;

    return;
}

int main()
{
    std::string s;
    std::string b;
    int aa = 4;
    int& bb = 312890;

    // int& Numb; << 컴파일 에러. 레퍼런스 변수는 선언하자마자 항상 초기화해줘야함.

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // b = nullptr; << 런타임 에러. string은 nullptr로 초기화 할수 없음.

    //Func(b);
    //Func1(nullptr);

    Func(aa);
    Func1(&aa);
    return 0;
}