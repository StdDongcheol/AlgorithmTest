// 2805.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

typedef long long ll;

ll arrN[1000000];

int main()
{
	ll N, M;
	ll Start, End;
	ll MaxLength = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
		std::cin >> arrN[i];
	
	std::sort(arrN, arrN + N);
	Start = 1;
	End = arrN[N - 1];
	
	while (Start <= End)
	{
		ll Middle = (Start + End) / 2;
		ll CurLength = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arrN[i] - Middle > 0)
			{
				CurLength += (arrN[i] - Middle);
			}
		}

		if (CurLength >= M)
		{
			MaxLength = std::max(MaxLength, Middle);
			Start = Middle + 1;
		}
		else if (CurLength < M)
			End = Middle - 1;
	}

	std::cout << MaxLength;
}
