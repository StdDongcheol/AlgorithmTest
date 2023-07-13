// 15686.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int arr[51][51];
int Dist[51][51];
bool Check[13];
int MinDist = 99999999;
std::vector<std::pair<int, int>> vecChick;
std::vector<std::pair<int, int>> vecHome;

void Comb(int _idx, int _count, int _max, std::vector<std::pair<int, int>> _vec)
{
	if (_count == _max)
	{
		for (int i = 0; i < _vec.size(); ++i)
		{
			int x = _vec[i].first;
			int y = _vec[i].second;

			for (int j = 0; j < vecHome.size(); ++j)
			{
				int x2 = vecHome[j].first;
				int y2 = vecHome[j].second;

				int CurDist = abs(x - x2) + abs(y - y2);
				
				if (CurDist < Dist[x2][y2])
				{
					Dist[x2][y2] = CurDist;
				}
			}
		}

		int SumDist = 0;
		for (int j = 0; j < vecHome.size(); ++j)
		{
			int x2 = vecHome[j].first;
			int y2 = vecHome[j].second;
			SumDist += Dist[x2][y2];
		}

		if (SumDist < MinDist)
			MinDist = SumDist;

		std::fill(Dist[0], Dist[0] + 2601, 99999999);

		return;
	}

	for (int i = _idx; i < vecChick.size(); ++i)
	{ 
		if (Check[i] == true)
			continue;
		Check[i] = true;
		_vec.push_back(vecChick[i]);
		Comb(i, _count + 1, _max, _vec);
		_vec.pop_back();
		Check[i] = false;
	}

}

int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::fill(Dist[0], Dist[0] + 2601, 99999999);
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			std::cin >> arr[i][j];

			if (arr[i][j] == 1)
				vecHome.push_back({ i, j });
			else if(arr[i][j] == 2)
				vecChick.push_back({ i, j });
		}
	}

	std::vector<std::pair<int, int>> vec;
	Comb(0, 0, M, vec);

	std::cout << MinDist;
}

