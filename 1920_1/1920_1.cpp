// 1920_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> vecN;
std::vector<int> vecM;

int main()
{
	std::cin >> N;
	vecN.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> vecN[i];
	}

	std::cin >> M;
	vecM.resize(M);
	for (int i = 0; i < M; ++i)
	{
		std::cin >> vecM[i];
	}

	std::sort(vecN.begin(), vecN.end());

	for (int i = 0; i < M; ++i)
	{
		int TargetN = vecM[i];

		int Start = 0;
		int End = N - 1;

		bool Check = false;
		while (Start <= End)
		{
			int Middle = (Start + End) / 2;
			
			if (vecN[Middle] == TargetN)
			{
				Check = true;
				break;
			}
			else if (vecN[Middle] < TargetN)
			{
				Start = Middle + 1;
			}
			else if (vecN[Middle] > TargetN)
			{
				End = Middle - 1;
			}
		}

		if (Check)
			std::cout << 1 << '\n';
		else
			std::cout << 0 << '\n';
	}

	return 0;
}
