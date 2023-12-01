// 1976.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> vecMap;
std::vector<bool> vecCheck;
std::queue<int> qTravel;
int N, M;

bool DFS(int _StartIndex, int _DestIndex)
{
	if (_StartIndex == _DestIndex)
	{
		return true;
	}
	
	vecCheck[_StartIndex] = true;

	for (int i = 0; i < vecMap[_StartIndex].size(); ++i)
	{
		int NextTown = vecMap[_StartIndex][i];

		if (vecCheck[NextTown] == false)
		{
			vecCheck[NextTown] = true;

			if (DFS(vecMap[_StartIndex][i], _DestIndex))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	std::cin >> N >> M;
	vecMap.resize(N + 1);
	vecCheck.resize(N + 1);
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; j++)
		{
			int Numb = 0;
			std::cin >> Numb;

			if (Numb == 1)
			{
				vecMap[i].push_back(j);
			}
		}
	}
	
	for (int i = 0; i < M; ++i)
	{
		int Town = 0;
		std::cin >> Town;
		qTravel.push(Town);
	}

	bool TravelOK = true;
	while (!qTravel.empty())
	{
		int StartIndex = qTravel.front();
		qTravel.pop();

		if (qTravel.empty())
			break;

		else
		{
			if (DFS(StartIndex, qTravel.front()) == false)
			{
				TravelOK = false;
				break;
			}
		}

		std::fill(vecCheck.begin(), vecCheck.end(), false);
	}

	if (TravelOK)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";


	return 0;
}
