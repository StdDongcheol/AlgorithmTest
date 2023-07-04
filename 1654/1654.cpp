// 1654.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, K;
	int LengthSum = 0;
	int CurLength = 0;
	std::vector<int> vecLength;
	std::vector<int> vecK;

	std::cin >> N >> K;

	vecLength.resize(N);
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> vecLength[i];
		LengthSum += vecLength[i];
	}

	int MaxLength = *std::max_element(vecLength.begin(), vecLength.end());

	CurLength = LengthSum / K;

	while (CurLength < MaxLength || CurLength > 0)
	{
		int Count = 0;
		for (int i = 0; i < N; ++i)
		{
			Count += (vecLength[i] / CurLength);
		}

		if (Count == K)
		{
			vecK.push_back(CurLength);
			break;
		}
		else if (Count < K)
		{
			--CurLength;
		}
		else if (Count > K)
		{
			++CurLength;
		}
	}

	int MaxValue = *std::max_element(vecK.begin(), vecK.end());

	std::cout << MaxValue;
}

