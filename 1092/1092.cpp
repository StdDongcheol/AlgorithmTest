// 1092.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

std::vector<int> vecN;
std::vector<int> vecM;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int N, M;
	std::cin >> N;
	vecN.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> vecN[i];
	}
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		int Numb;
		std::cin >> Numb;
		vecM.push_back(Numb);
	}

	std::sort(vecN.rbegin(), vecN.rend());
	std::sort(vecM.rbegin(), vecM.rend());

	if (vecN.front() < vecM.front())
	{
		std::cout << -1;
		return 0;
	}

	int Second = 0;
	while (true)
	{
		bool Check = false;
		int Index = 0;

		for (int j = 0; j < M; ++j)
		{
			if (Index >= N)
				break;

			if (vecM[j] < 0)
				continue;
			
			int CurBox = vecM[j];

			if (vecN[Index] >= CurBox)
			{
				Check = true;
				vecM[j] = -1;
				++Index;
			}
		}

		if (Check == false)
		{
			break;
		}

		++Second;
	}

	std::cout << Second;

	return 0;
}