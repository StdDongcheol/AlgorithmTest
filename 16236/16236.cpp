// 16236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

int map[20][20];
int dist[20][20];
bool check[20][20];
int Level = 2;
int CurExp = 0;
int N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct comp
{
	bool operator()(std::pair<int, std::pair<int, int>> _l, std::pair<int, std::pair<int, int>> _r)
	{
		if (_l.first == _r.first)
		{
			if (_l.second.second == _r.second.second)
			{
				return _l.second.first > _r.second.first;
			}
			else
				return _l.second.second > _r.second.second;
		}
		else
			return _l.first > _r.first;
	}
};

std::queue<std::pair<int, std::pair<int, int>>> q;
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, comp> pq;

void BFSDistSearch(int _CurX, int _CurY)
{
	std::queue<std::pair<int, std::pair<int, int>>> DistQ;

	DistQ.push({ 0, {_CurX, _CurY} });
	dist[_CurY][_CurX] = 0;
	check[_CurY][_CurX] = true;

	while (!DistQ.empty())
	{
		int CurFishX = DistQ.front().second.first;
		int CurFishY = DistQ.front().second.second;
		DistQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurFishX + dx[i];
			int NextY = CurFishY + dy[i];

			if (0 <= NextX && NextX < N && 0 <= NextY && NextY < N && check[NextY][NextX] == false)
			{
				if (0 <= map[NextY][NextX] && map[NextY][NextX] <= Level)
				{
					check[NextY][NextX] = true;
					dist[NextY][NextX] = dist[CurFishY][CurFishX] + 1;
					DistQ.push({ dist[NextY][NextX], {NextX, NextY} });
				}
			}
		}
	}

	std::fill(check[0], check[20], false);

	return;
}

int Search(int _x, int _y)
{
	int Count = 0;

	while (!q.empty())
	{
		pq.push(q.front());
		q.pop();
	}

	int CurX = _x, CurY = _y;
	
	while (!pq.empty())
	{
		int CurFishX = pq.top().second.first;
		int CurFishY = pq.top().second.second;
		Count += pq.top().first;
		map[CurFishY][CurFishX] = 0;
		pq.pop();

		CurX = CurFishX;
		CurY = CurFishY;
		++CurExp;


		if (CurExp == Level)
		{
			++Level;
			CurExp = 0;
		}

		// 모든 물고기 Dist를 갱신
		// 자신의 위치에서 BFS수행
		BFSDistSearch(CurX, CurY);

		while(!pq.empty())
			pq.pop();

		// 먹을수 있는 물고기를 모두 체크
		if (q.empty() && pq.empty())
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; j++)
				{
					if (0 < map[i][j] && map[i][j] < Level && dist[i][j] != 0)
					{
						q.push({ dist[i][j], {j, i}});
					}
				}
			}
		}

		while (!q.empty())
		{
			pq.push(q.front());
			q.pop();
		}
	}

	return Count;
}

int main()
{
	std::cin >> N;
	int StartX = 0, StartY = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == 9)
			{
				StartX = j;
				StartY = i;
				map[i][j] = 0;
			}
		}
	}


	BFSDistSearch(StartX, StartY);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			if (0 < map[i][j] && map[i][j] < Level && dist[i][j] != 0)
			{
				q.push({ dist[i][j], {j, i} });
			}
		}
	}

	std::cout << Search(StartX, StartY);

	return 0;
}

