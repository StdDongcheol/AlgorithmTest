// 1940.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{	// S		 E	
	// 1 2 3 4 5 7
	
	int N, M;
	int Count = 0;

	std::cin >> N;
	std::cin >> M;
	std::vector<int> Numb;

	Numb.resize(N, 0);

	int Begin, End;
	Begin = 0;
	End = N - 1;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> Numb[i];
	}
	
	std::sort(Numb.begin(), Numb.end());

	while (Begin != End &&
		Begin < N && End >= 0)
	{
		int Sum = 0;

		if (Numb[Begin] == -1)
		{
			++Begin;
			continue;
		}

		if (Numb[End] == -1)
		{
			--End;
			continue;
		}

		if (Numb[Begin] + Numb[End] == M)
		{
			Numb[Begin++] = -1;
			Numb[End--] = -1;
			++Count;
		}

		else if (Numb[Begin] + Numb[End] > M)
		{
			--End;
		}

		else if (Numb[Begin] + Numb[End] < M)
		{
			++Begin;
		}
	}

	std::cout << Count;
}