// 1495_Jungol.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int dx[3] = {1, -1, 1};
int dy[3] = {0, 1, -1};
int vec[100][100] = {};

// dx,dy의 index 0의 이동방향과,
// MoveIndex 0에서 초기 대각선 진행방향을 우측상단인지 좌측하단인지 지정하면
// 지그재그 진행방향을 바꿀수 있다.
int main()
{
    int N;
    std::cin >> N;

    int MoveIndex = 0;
    int Count = 1;
    int CurX = 0;
    int CurY = 0;

    vec[CurX][CurY] = Count;
    ++Count;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 하단체크
            switch (MoveIndex)
            {
            case 0:
            {
                CurX += dx[MoveIndex];
                CurY += dy[MoveIndex];
                vec[CurX][CurY] = Count;
                MoveIndex = 1;
            }
                break;

                // 우측상단 대각선이동
            case 1:
                if (CurX + dx[MoveIndex] >= 0 && CurY + dy[MoveIndex] < N)
                {
                    CurX += dx[MoveIndex];
                    CurY += dy[MoveIndex];
                    vec[CurX][CurY] = Count;
                }


                // 오른쪽으로 갈 수 있는지
                else if(CurY + 1 < N)
                {
                    CurY += 1;
                    vec[CurX][CurY] = Count;
                    MoveIndex = 2;
                }

                // 아래로 내려갈 수 있는지
                else if (CurX + 1 < N)
                {
                    CurX += 1;
                    vec[CurX][CurY] = Count;
                    MoveIndex = 2;
                }
                break;

                // 왼쪽아래 대각선이동
            case 2:
                if (CurX + dx[MoveIndex] < N && CurY + dy[MoveIndex] >= 0)
                {
                    CurX += dx[MoveIndex];
                    CurY += dy[MoveIndex];
                    vec[CurX][CurY] = Count;
                }

                // 아래로 내려갈수 있는지
                else if (CurX + 1 < N)
                {
                    CurX += 1;
                    vec[CurX][CurY] = Count;
                    MoveIndex = 1;
                }

                // 오른쪽으로는 갈수 있는지
                else if (CurY + 1 < N)
                {
                    CurY += 1;
                    vec[CurX][CurY] = Count;
                    MoveIndex = 1;
                }
                break;
            }
            
            ++Count;
        }
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
