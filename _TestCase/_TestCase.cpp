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
    std::string strSrc = "블끼얏호우~!";
    
    std::string& strRef = strSrc;
    
    std::string strSrc2 = "돈스탑더뮤직~~!";

    char* c = new char[40];
    
    return 0;
}