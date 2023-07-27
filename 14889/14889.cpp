// 14889.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int arr[20][20];
int N;
int answer = 99999999;
bool Check[20];

void Comb(int _Index, int _Count, int _MaxCount)
{
    if (_Count == _MaxCount / 2)
    {
        int Start = 0, Link = 0;

        for (int i = 0; i < _MaxCount; ++i)
        {
            for (int j = i + 1; j < _MaxCount; ++j)
            {
                if (Check[i] && Check[j])
                    Start += arr[i][j] + arr[j][i];
                else if(!Check[i] && !Check[j])
                    Link += arr[i][j] + arr[j][i];
            }
        }
        answer = std::min(answer, abs(Start - Link));
    }

    for (int i = _Index; i < _MaxCount; ++i)
    {
        if (!Check[i])
        {
            Check[i] = true;
            Comb(i + 1, _Count + 1, _MaxCount);
            Check[i] = false;
        }
    }
}


int main()
{
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    Comb(0, 0, N);

    std::cout << answer;

}
