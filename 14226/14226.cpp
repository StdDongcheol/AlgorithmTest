// 14226.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[2001][2001];

int main()
{
	std::queue<std::pair<int, int>> q;

	int S;
	std::cin >> S;

	arr[1][0] = 0;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int CurCount = q.front().first;
		int CurCilp = q.front().second;
		q.pop();

		if (CurCount == S)
		{
			std::cout << arr[CurCount][CurCilp];
			break;
		}

		int NextX[3] = { CurCount, CurCount + CurCilp, CurCount - 1 };
		int NextY[3] = { CurCount , CurCilp ,CurCilp };

		for (int i = 0; i < 3; ++i)
		{
			if (NextX[i] <= 2000 && NextX[i] >= 0 && NextY[i] <= 2000 && NextY[i] >= 0)
			{
				if (arr[NextX[i]][NextY[i]] == 0)
				{
					arr[NextX[i]][NextY[i]] += (arr[CurCount][CurCilp] + 1);
					q.push({ NextX[i] , NextY[i] });
				}
			}
		}
	}

	return 0;
}