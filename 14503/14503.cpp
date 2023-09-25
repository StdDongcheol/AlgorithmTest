// 14503.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[50][50];
bool check[50][50];

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Rotate(int _dir)
{
	int NewDir = (_dir - 1) < 0 ? 3 : (_dir - 1);

	return NewDir;
}

int RearDir(int _dir)
{
	int NewDir = 0;
	switch (_dir)
	{
	case 0:
		NewDir = 2;
		break;
	case 1:
		NewDir = 3;
		break;
	case 2:
		NewDir = 0;
		break;
	case 3:
		NewDir = 1;
		break;
	}

	return NewDir;
}

int BFS(int _x, int _y, int _dir)
{
	std::queue<std::pair<std::pair<int, int>, int>> q;
	q.push({ { _x, _y }, _dir });

	int Count = 0;
	
	while (!q.empty())
	{
		int CurX = q.front().first.first;
		int CurY = q.front().first.second;
		int CurDir = q.front().second;
		q.pop();

		if (arr[CurX][CurY] == 0 && check[CurX][CurY] == false)
		{
			++Count;
			check[CurX][CurY] = true;
		}

		bool Check = false;
		int Dir = CurDir;
		for (int i = 0; i < 4; ++i)
		{
			int NextDir = Rotate(Dir);
			int NextX = CurX + dx[NextDir];
			int NextY = CurY + dy[NextDir];

			if (arr[NextX][NextY] == 0 && check[NextX][NextY] == false)
			{
				q.push({ { NextX, NextY }, NextDir });
				Check = true;
				break;
			}
			Dir = NextDir;
		}

		if (Check)
			continue;
		else
		{
			int BackDir = RearDir(Dir);
			int RearX = CurX + dx[BackDir];
			int RearY = CurY + dy[BackDir];

			if (arr[RearX][RearY] == 0)
				q.push({ {RearX, RearY}, Dir });
			else
				break;
		}
	}

	return Count;
}

int main()
{
	int StartX, StartY, Dir;

	std::cin >> N >> M;
	std::cin >> StartX >> StartY >> Dir;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	std::cout << BFS(StartX, StartY, Dir);

	return 0;
}
