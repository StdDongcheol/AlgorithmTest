// 1449.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int N, L;
int water[1000];

int main()
{
	int Count = 0;
	std::cin >> N >> L;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> water[i];
	}

	std::sort(water, water + N);
	
	int Start = water[0];

	for (int i = 1; i < N; ++i)
	{
		if (L <= water[i] - Start)
		{
			++Count;
			Start = water[i];
		}
	}

	std::cout << Count + 1;
	
	return 0;
}