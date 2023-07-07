// 1920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int arrN[100000];
int arrM[100000];

int main()
{
	int N, M;

	std::cin >> N;
	for (int i = 0; i < N; ++i) 
		std::cin >> arrN[i];

	std::cin >> M;
	for (int i = 0; i < M; ++i)
		std::cin >> arrM[i];

	std::sort(arrN, arrN + N);

	for (int i = 0; i < M; ++i)
	{
		int Start = 0;
		int End = N - 1;

		bool Check = false;
		while (Start <= End)
		{
			int Middle = (Start + End) / 2;
			if (arrN[Middle] == arrM[i])
			{
				Check = true;
				break;
			}
			else if (arrN[Middle] < arrM[i])
			{
				Start = Middle + 1;
			}
			else if (arrN[Middle] > arrM[i])
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