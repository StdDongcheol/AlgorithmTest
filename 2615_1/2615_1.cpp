// 2615_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int arr[19][19];
int N = 19;

int dx[4] = { 1, 0, 1, 1 };
int dy[4] = { 0, 1, 1, -1 };

bool CheckFive(int _x, int _y, int _Color)
{
	for (int i = 0; i < 4; ++i)
	{
		int CurX = _x + dx[i];
		int CurY = _y + dy[i];

		int Count = 1;
		if (CurX < N && CurX >= 0 && CurY < N && CurY >= 0)
		{
			for (int j = 0; j < 4; ++j)
			{
				int NextX = CurX + (dx[i] * j);
				int NextY = CurY + (dy[i] * j);
				
				if (NextX < N && NextX >= 0 && NextY < N && NextY >= 0)
				{
					int NextColor = arr[NextY][NextX];

					if (NextColor == _Color)
					{
						++Count;
					}
				}
			}
		}

		bool Check = true;
		if (Count == 5)
		{
			if (i == 0)
			{
				if ((_x < 14 && arr[_y][_x] == arr[_y][_x + 5]) ||
					(_x > 0 && arr[_y][_x] == arr[_y][_x - 1]))
					Check = false;
				else
					return true;
			}
			if (i == 1)
			{
				if ((_y < 14 && arr[_y][_x] == arr[_y + 5][_x]) ||
					(_y > 0 && arr[_y][_x] == arr[_y - 1][_x]))
					Check = false;
				else
					return true;
			}
			if (i == 2)
			{
				if ((_y < 14 && _x < 14 && arr[_y][_x] == arr[_y + 5][_x + 5]) ||
					(_y > 0 && _x > 0 && arr[_y][_x] == arr[_y - 1][_x - 1]))
					Check = false;
				else
					return true;
			}
			if (i == 3)
			{
				if ((_y > 4 && _x < 14 && arr[_y][_x] == arr[_y - 5][_x + 5]) ||
					(_y < 18 && _x > 0 && arr[_y][_x] == arr[_y + 1][_x - 1]))
					Check = false;
				else
					return true;
			}
		}
	}

	return false;
}

int main()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[j][i] != 0)
			{
				if (CheckFive(i, j, arr[j][i]))
				{
					std::cout << arr[j][i] << '\n';
					std::cout << j + 1 << " " << i + 1;	
					return 0;
				}
			}
		}
	}

	std::cout << 0 << '\n';

	return 0;
}