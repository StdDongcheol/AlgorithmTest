// 16236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int map[20][20];
int Level = 2;
int exp = 0;
int N;
std::queue<std::pair<int, std::pair<int, int>>> q;
std::priority_queue<std::pair<int, std::pair<int, int>>> pq;


int Search(int _x, int _y)
{
	int Count = 0;

	
	while (!q.empty())
	{
		pq.push(q.front());
		q.pop();
	}

	int MinDist = 999999;
	int MinX = 999999;
	int MinY = 999999;
	int CurX = _x, CurY = _y;

	std::string str;
	std::cin >> str;


	while (!pq.empty())
	{
		int FishX = pq.top().second.first;
		int FishY = pq.top().second.second;
		int CurDist = abs(CurX - FishX) + abs(CurY - FishY);

		if (CurDist <= MinDist)
		{
			if (CurDist == MinDist)
			{

			}
			else
			{
				MinX = FishX;
				MinY = FishY;
				MinDist = CurDist;
			}
		}
		

		// 먹을수 있는 물고기를 모두 체크(N * N)

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
			}
			else if (map[i][j] == 2)
			{
				int Dist = abs(StartY - i) + abs(StartX - j);
				q.push({ Dist, {j , i} });
			}
		}
	}

	std::cout << Search(StartX, StartY);

	return 0;
}

