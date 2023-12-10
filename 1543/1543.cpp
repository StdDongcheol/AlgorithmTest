
// 1543.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int Check(std::string& _src, std::string& _dst)
{
    int Count = 0;
    int Length = _src.length() - _dst.length();
    
    for (int i = 0; i <= Length; ++i)
    {
        bool IsCheck = true;
        int Index = 0;

        for (int j = 0; j < _dst.length(); j++)
        {
            if (_dst[j] != _src[i + j])
            {
                IsCheck = false;
                break;
            }
        }

        if (IsCheck)
        {
            i += _dst.length() - 1;
            ++Count;
        }
    }

    return Count;
}

int main()
{
    std::string SrcStr;
    std::string str;
    std::getline(std::cin, SrcStr);
    std::getline(std::cin, str);

    std::cout << Check(SrcStr, str);

    return 0;
}
