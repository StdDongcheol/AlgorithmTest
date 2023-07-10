// 3184.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

char arr[251][251];
bool Check[251][251];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C;
int Wolverines;
int Lamb;

void BFS(int _x, int _y)
{
	std::queue <std::pair<int, int >> q;
	q.push({ _x, _y});

	int CurLamb = 0;
	int CurWolv = 0;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		Check[CurY][CurX] = true;

		if (arr[CurY][CurX] == 'v')
			++CurWolv;
		else if (arr[CurY][CurX] == 'o')
			++CurLamb;

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX > 0 && NextX <= C && NextY > 0 && NextY <= R && arr[NextY][NextX] != '#' && Check[NextY][NextX] == false)
			{
				q.push({ NextX, NextY });
				Check[NextY][NextX] = true;
			}
		}
	}
	if (CurLamb > CurWolv)
		Lamb += CurLamb;
	else if (CurLamb <= CurWolv)
		Wolverines += CurWolv;
}

int main()
{
	std::cin >> R >> C;

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			std::cin >> arr[i][j];
	
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (!Check[i][j] && arr[i][j] != '#')
				BFS(j, i);
		}
	}

	std::cout << Lamb << " " << Wolverines;
}