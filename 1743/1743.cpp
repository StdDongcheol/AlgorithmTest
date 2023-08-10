// 1743.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[101][101];
bool Check[101][101];
int N, M, K;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int _X, int _Y)
{
	std::queue<std::pair<int, int>> q;
	
	int Size = 1;

	q.push({_X, _Y});
	Check[_Y][_X] = true;

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX <= M && NextX > 0 && NextY <= N && NextY > 0)
			{
				if (arr[NextY][NextX] == true && !Check[NextY][NextX])
				{
					++Size;
					Check[NextY][NextX] = true;
					q.push({ NextX, NextY });
				}
			}
		}
	}

	return Size ;
}

int main()
{
	std::cin >> N >> M >> K;
	
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		arr[x][y] = 1;
	}

	int maxCount = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) 
		{
			if (arr[i][j] == 1 && !Check[i][j])
				maxCount = std::max(maxCount, BFS(j, i));
		}
	}

	std::cout << maxCount;

	return 0;
}