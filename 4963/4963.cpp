#include <iostream>
#include <queue>

int arrMap[51][51] = {};
bool arrCheck[51][51] = {};
int W, H;
int dx[8] = { 1, 0, -1,  0, 1, -1,  1, -1 };
int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

bool DFS(int _x, int _y)
{
	if (!arrCheck[_x][_y])
		arrCheck[_x][_y] = true;

	int CurX = _x;
	int CurY = _y;

	for (int i = 0; i < 8; ++i)
	{
		int NextX = CurX + dx[i];
		int NextY = CurY + dy[i];

		if (NextX > 0 && NextX <= H &&
			NextY > 0 && NextY <= W)
		{
			if (arrMap[NextX][NextY] == 1 && !arrCheck[NextX][NextY])
			{
				DFS(NextX, NextY);
			}
		}
	}

	return true;
}

int main()
{
	while (true)
	{
		int Count = 0;
		std::cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= W; ++j)
			{
				std::cin >> arrMap[i][j];
			}
		}

		for (int i = 1; i <= H; ++i)
		{
			for (int j = 1; j <= W; ++j)
			{
				if (!arrCheck[i][j] && arrMap[i][j] == 1)
				{
					DFS(i, j);
					++Count;
				}
			}
		}

		std::fill(arrMap[0], arrMap[0] + 2601, 0);
		std::fill(arrCheck[0], arrCheck[0] + 2601, false);
		std::cout << Count << "\n";
	}
}
