// 3100.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

char Arr[6][9];
int alphabet[26];

int main()
{
    for (int i = 0; i < 6; ++i)
        std::cin.getline(Arr[i], 10);

    int RowCount = 0;
    int ColCount = 0;

    for (int i = 0; i < 2; ++i)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 6; ++j)
            {
                for (int k = 0; k < 9; ++k)
                {
                    ++alphabet[Arr[j][k] - 'A'];
                }

                if ((j + 1) % 2 == 0)
                {
                    int MaxCount = *std::max_element(alphabet, alphabet + 26);

                    ColCount += (18 - MaxCount);

                    std::fill(alphabet, alphabet + 26, 0);
                }
            }
        }

        else
        {
            for (int j = 0; j < 9; ++j)
            {
                for (int k = 0; k < 6; ++k)
                {
                    ++alphabet[Arr[k][j] - 'A'];
                }

                if ((j + 1) % 3 == 0)
                {
                    int MaxCount = *std::max_element(alphabet, alphabet + 26);

                    RowCount += (18 - MaxCount);

                    std::fill(alphabet, alphabet + 26, 0);
                }
            }
        }
    }

    std::cout << std::min(RowCount, ColCount);

    return 0;
}
