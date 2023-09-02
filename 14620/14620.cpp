


#include <iostream>

int MinValue = 3001;
int N;
int arr[10][10];
bool check[10][10];

int dx[4] = {1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1 };

bool checkArr(int _x, int _y)
{
    if (check[_y][_x])
        return false;

    for (int i = 0; i < 4; ++i)
    {
        int X = _x + dx[i];
        int Y = _y + dy[i];

        if (X >= N || X < 0 || Y >= N || Y < 0)
            return false;

        if (check[Y][X])
            return false;
    }

    check[_y][_x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int X = _x + dx[i];
        int Y = _y + dy[i];

        check[Y][X] = true;
    }

    return true;
}

void releaseCheck(int _x, int _y)
{
    check[_y][_x] = false;

    for (int k = 0; k < 4; ++k)
    {
        int X = _x + dx[k];
        int Y = _y + dy[k];

        check[Y][X] = false;
    }

    return;
}

void Find(int _CurCount, int _MaxCount)
{
    if (_CurCount == _MaxCount)
    {
        int CurValue = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (check[i][j])
                    CurValue += arr[i][j];
            }
        }

        MinValue = std::min(CurValue, MinValue);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (checkArr(j, i))
            {
                Find(_CurCount + 1, _MaxCount);
                releaseCheck(j, i);
            }
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

    Find(0, 3);

    std::cout << MinValue;
}
