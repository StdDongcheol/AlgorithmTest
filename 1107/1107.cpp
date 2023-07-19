// 1107.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int arrNumb[10] = { 0,1,2,3,4,5,6,7,8,9 };
std::vector<int> vec;

int Find(int _TargetChannel)
{
    int Count = 0;
    int CurChannel = 100;
    if (_TargetChannel == CurChannel)
        return Count;

    for (int CurNum : vec)
    {
        if (abs(CurNum - _TargetChannel) < abs(CurChannel - _TargetChannel))
        {
            CurChannel = CurNum;
        }
    }

    // 자리수 구하기
    int Numb = CurChannel;
    while (Numb / 10 != 0 || Numb % 10 != 0)
    {
        ++Count;
        int BackNumb = Numb % 10;
        if (arrNumb[BackNumb] == -1)
            break;
        Numb /= 10;
    }

    if (CurChannel == 0)
        ++Count;

    while (_TargetChannel != CurChannel)
    {
        if (CurChannel < _TargetChannel)
            ++CurChannel;
        else if (CurChannel > _TargetChannel)
            --CurChannel;
        else
            break;

        ++Count;
    }


    return std::min(abs(_TargetChannel - 100), Count);
}

int main()
{
    int Channel;
    int N;
    std::cin >> Channel;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int Broken;
        std::cin >> Broken;
        arrNumb[Broken] = -1;
    }

    if (arrNumb[0] != -1)
        vec.push_back(0);

    for (int i = 1; i <= 1000000; ++i)
    {
        int CurNum = i;
        bool Check = true;
        while (CurNum / 10 != 0 || CurNum % 10 != 0)
        {
            int BackNumb = CurNum % 10;
            if (arrNumb[BackNumb] == -1)
            {
                Check = false;
                break;
            }
            CurNum /= 10;
        }

        if(Check)
            vec.push_back(i);
    }

    std::cout << Find(Channel);
}
