// 10989.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int Numb;
    std::vector<int> vecData;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;

    vecData.resize(10001, 0);

    for (int i = 1; i <= N; ++i)
    {
        std::cin >> Numb;
        ++vecData[Numb];
    }
        
    for (int i = 1; i <= 10000; ++i)
    {
        for (int j = 0; j < vecData[i]; ++j)
            std::cout << i << "\n";
    }

    return 0;
}
