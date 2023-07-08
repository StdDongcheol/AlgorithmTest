// 2512.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int arrN[10000];

int main()
{
	int N, M;
	int Start, End;
	int Budget = 0;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arrN[i];
	
	std::sort(arrN, arrN + N);
	Start = 1;
	End = arrN[N - 1];

	std::cin >> M;

	while (Start <= End)
	{
		int Middle = (Start + End) / 2;
		int CurBudget = 0;

		for (int i = 0; i < N; ++i)
		{
			if (arrN[i] < Middle)
				CurBudget += arrN[i];
			else if (arrN[i] >= Middle)
				CurBudget += Middle;
		}

		if (CurBudget <= M)
		{
			Budget = std::max(Budget, Middle);
			Start = Middle + 1;
		}
		else if (CurBudget > M)
		{
			End = Middle - 1;
		}
	}

	std::cout << Budget;
}