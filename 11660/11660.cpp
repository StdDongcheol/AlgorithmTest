// 11660.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    int N, M = 0;

    int Number[1025][1025] = { 0 };
    int Arr[1025][1025] = { 0 };

    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int Numb = 0;
            std::cin >> Numb;

            Number[i][j] = Numb;
            Arr[i][j] = Arr[i][j - 1] + Numb;
        }
    }

    for (int Count = 0; Count < M; ++Count)
    {
        int x1, y1, x2, y2 = 0;
        int Sum = 0;

        // (2,2)  (3,4)
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2 && y1 == y2)
        {
            std::cout << Number[x1][y1] << "\n";
            continue;
        }

        // 첫줄 선계산
        Sum = Arr[x1][y2] - Arr[x1][y1 - 1];

        // 높이 계산
        int RowCount = x2 - x1;

        for (int i = 1; i <= RowCount; ++i)
        {
            Sum += (Arr[x1 + i][y2] - Arr[x1 + i][y1 - 1]);
        }

        std::cout << Sum << "\n";
    }
}
