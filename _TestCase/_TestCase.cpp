// _TestCase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>


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

int n = 5;
int k = 3;

void combi(int Start, std::vector<int> vec, std::vector<int>& vecTarget)
{
    if (vec.size() == k)
    {
        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << "\n";
        return;
    }

    for (int i = Start + 1; i < n; ++i)
    {
        vec.push_back(vecTarget[i]);
        combi(i, vec, vecTarget);
        vec.pop_back();
    }
}

int main()
{
    std::string strSrc = "블끼얏호우~!";
    
    std::string& strRef = strSrc;
    
    std::string strSrc2 = "돈스탑더뮤직~~!";

    char* c = new char[40];
    
    std::vector<int> vec;
    std::vector<int> vecTarget = { 5, 6, 7, 8, 9 };

    combi(-1, vec, vecTarget);

    return 0;
}