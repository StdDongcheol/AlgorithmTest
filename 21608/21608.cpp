// 21608.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

std::map<int, std::pair<int, int>> mapPos;
std::vector<std::vector<int>> vecStudent;
int map[20][20];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool Sort(std::pair<int, std::pair<int, int>>& _l, 
	std::pair<int, std::pair<int, int>> _r)
{
	if (_l.first == _r.first)
	{
		if (_l.second.second == _l.second.second)
		{
			return _l.second.first < _l.second.first;
		}

		return _l.second.second < _l.second.second;
	}

	return _l.first > _r.first;
}

void FindSit(int _Numb)
{
	std::vector<std::pair<int, std::pair<int, int>>> vecPos;

	bool Check = false;
	for (int i = 0; i < vecStudent[_Numb].size(); ++i)
	{
		int SNumber = vecStudent[_Numb][i];

		auto iter = mapPos.find(SNumber);

		if (iter == mapPos.end())
		{
			continue;
		}

		else
		{
			Check = true;
			int X = iter->second.first;
			int Y = iter->second.second;
			int Count = 1;

			for (int k = 0; k < 4; ++k)
			{
				int NearX = X + dx[k];
				int NearY = Y + dy[k];

				if (0 <= NearY && NearY < N && 0 <= NearX && NearX < N)
				{
					for (int index = 0; index < vecStudent[_Numb].size(); ++index)
					{
						int CurS = vecStudent[_Numb][index];
						if (CurS == map[NearY][NearX])
						{
							++Count;
						}
					}
				}
				  
				vecPos.push_back({ Count, {NearX, NearY} });
			}
		}
	}


	// 친구가 없을경우
	if (Check == false)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int Count = 0;

				for (int k = 0; k < 4; ++k)
				{
					int NearX = j + dx[k];
					int NearY = i + dy[k];

					if (0 <= NearY && NearY < N && 0 <= NearX && NearX < N)
					{
						if (map[NearY][NearX] == 0)
						{
							++Count;
						}
					}
				}

				if (Count > 0)
					vecPos.push_back({ Count, {j, i} });
			}
		}
	
		std::sort(vecPos.begin(), vecPos.end(), Sort);

		int ResultX = vecPos[0].second.first;
		int ResultY = vecPos[0].second.second;

		map[ResultY][ResultX] = _Numb;
		mapPos.insert({ _Numb, {ResultX, ResultY} });
		return;
	}

	// 친구가 있을경우
	else
	{

	}
}

int main()
{
	std::cin >> N;
	vecStudent.resize(N * N);

	for (int i = 1; i <= N * N; ++i)
	{
		int SNumber, S1, S2, S3, S4;
		std::cin >> SNumber >> S1 >> S2 >> S3 >> S4;
		
		vecStudent[SNumber].push_back(S1);
		vecStudent[SNumber].push_back(S2);
		vecStudent[SNumber].push_back(S3);
		vecStudent[SNumber].push_back(S4);

		FindSit(SNumber);
	}

	return 0;
}