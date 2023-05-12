// 2559.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, K;

    std::vector<int> vecTemp;
    std::vector<int> vec;
    std::cin >> N >> K;

    vecTemp.resize(N);
    
    for (int i = 0; i < N; ++i)
        std::cin >> vecTemp[i];

    int Start = 0;
    int End = K;
    int Sum = 0;

    for (int i = Start; i < End; ++i)
    {
        Sum += vecTemp[i];
    }
    vec.push_back(Sum);


    while (End < N)
    {
        Sum -= vecTemp[Start];
        ++Start;

        if (End < N)
            Sum += vecTemp[End];
        else
            break;

        ++End;

        vec.push_back(Sum);
    }
    
    std::cout << *std::max_element(vec.begin(), vec.end());

    return 0;
}
