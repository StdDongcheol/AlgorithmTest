// 14500.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int arr[500][500];
int TetArr[19][4][2] =
{
    {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0}
    },
    {
        {0, 0},
        {0, 1},
        {0, 2},
        {0, 3}
    },
    {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    },
    {   // ㅜ
        {0, 0},
        {1, 0},
        {1, 1},
        {2, 0}
    },
    {   // ㅏ
        {0, 0},
        {0, 1},
        {1, 1},
        {0, 2}
    },
    {   // ㅓ
        {1, 0},
        {1, 1},
        {1, 2},
        {0, 1}
    },
    {   // ㅗ
        {0, 1},
        {1, 1},
        {2, 1},
        {1, 0}
    },
    {   // s up
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 2}
    },
    {   // s down
        {0, 1},
        {1, 1},
        {1, 0},
        {2, 0}
    },
    {   // z up
        {1, 0},
        {1, 1},
        {0, 1},
        {0, 2}
    },
    {   // z down
        {0, 0},
        {1, 0},
        {1, 1},
        {2, 1}
    },
    {   // L
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 2}
    },
    {   // L ->90 rot
        {0, 0},
        {0, 1},
        {1, 0},
        {2, 0}
    },
    {   // L ->180 rot
        {0, 0},
        {1, 0},
        {1, 1},
        {1, 2}
    },
    {   // L ->270 rot
        {2, 0},
        {2, 1},
        {1, 1},
        {0, 1}
    },
    {   // J
        {1, 0},
        {1, 1},
        {1, 2},
        {0, 2}
    },
    {   // J ->90 rot
        {0, 0},
        {0, 1},
        {1, 1},
        {2, 1}
    },
    {   // J ->180 rot
        {0, 0},
        {1, 0},
        {0, 1},
        {0, 2}
    },
    {   // L ->270 rot
        {0, 0},
        {1, 0},
        {2, 0},
        {2, 1}
    }
};
int N, M;

int CheckTetris(int _x, int _y)
{
    int resultSum = 0;
    for (int k = 0; k < 19; ++k)
    {
        int CurSum = 0;
        for (int i = 0; i < 4; ++i)
        {
            int CurX = _x + TetArr[k][i][0]; // X;
            int CurY = _y + TetArr[k][i][1]; // Y;

            if(CurX >= 0 && CurX < M && CurY >= 0 && CurY < N)
                CurSum += arr[CurY][CurX];
        }
        if (resultSum < CurSum)
            resultSum = CurSum;
    }

    return resultSum;
}

int main()
{
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> arr[i][j];

    int MaxValue = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int Value = CheckTetris(j, i);
            if (MaxValue < Value)
                MaxValue = Value;
        }
    }

    std::cout << MaxValue;
}
