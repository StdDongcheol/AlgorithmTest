// 1920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N, M;
	std::vector<int> vecN;
	std::vector<int> vecM;

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

	// vecN에서 vecM찾기
	for (int i = 0; i < M; ++i)
	{
		int Check = false;
		int Start = 0;
		int End = vecN.size() - 1;
		int TargetValue = vecM[i];

		while (Start <= End)
		{
			int Mid = (Start + End) / 2;
			int MidValue = vecN[Mid];

			if (TargetValue == MidValue)
			{
				Check = true;
				break;
			}

			// Target이 더 크다면
			else if (TargetValue > vecN[Mid])
			{
				Start = Mid + 1;
			}

			// Target이 작다면
			else if (TargetValue < vecN[Mid])
			{
				End = Mid - 1;
			}
		}

		if (Check)
			std::cout << 1 << "\n";
		else
			std::cout << 0 << "\n";
	}

}
