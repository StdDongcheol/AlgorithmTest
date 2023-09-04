// 7569.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

struct Data 
{
public:
	Data(int _x, int _y, int _z) :
		x(_x),	y(_y), z(_z)
	{
	}

public:
	int x;
	int y;
	int z;
};

int arr[100][100][100];
bool check[100][100][100];
int N, M, H;
int MaxDay = 1;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
std::queue<Data> qData;

bool CheckIndexValid(int _x, int _y, int _z)
{
	// 인덱스 유효검사
	if (_x >= M || _x < 0)
		return false;
	if (_y >= N || _y < 0)
		return false;
	if (_z >= H || _z < 0)
		return false;

	// 이미 방문했거나 토마토가 없으면 false
	if (check[_z][_y][_x] == true || arr[_z][_y][_x] == -1)
		return false;

	return true;
}

void BFS(int _x, int _y, int _z)
{
	std::queue<Data> q;
	
	while (!qData.empty())
	{
		q.push(qData.front());
		int CurX = qData.front().x;
		int CurY = qData.front().y;
		int CurZ = qData.front().z;
		check[CurZ][CurY][CurX] = true;
		qData.pop();
	}

	
	while (!q.empty())
	{
		int CurX = q.front().x;
		int CurY = q.front().y;
		int CurZ = q.front().z;

		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int NextX = dx[i] + CurX;
			int NextY = dy[i] + CurY;
			int NextZ = dz[i] + CurZ;

			if (CheckIndexValid(NextX, NextY, NextZ) && arr[NextZ][NextY][NextX] == 0)
			{
				arr[NextZ][NextY][NextX] += (arr[CurZ][CurY][CurX] + 1);
				check[NextZ][NextY][NextX] = true;
				MaxDay = std::max(arr[NextZ][NextY][NextX], MaxDay);
				q.push(Data(NextX, NextY, NextZ));
			}
		}
	}
}

int main()
{
	std::cin >> M >> N >> H;

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				std::cin >> arr[k][i][j];
				if (arr[k][i][j] == 1)
				{
					qData.push(Data(j, i, k));
				}
			}
		}
	}

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (CheckIndexValid(j, i, k) && arr[k][i][j] == 1)
					BFS(j, i, k);
			}
		}
	}

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[k][i][j] == 0)
				{
					std::cout << -1;
					return 0;
				}
			}
		}
	}

	std::cout << MaxDay - 1;

	return 0;
}
