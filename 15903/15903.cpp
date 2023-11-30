// 15903.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

int N, M;

int main()
{
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		long long Numb = 0;
		std::cin >> Numb;
		pq.push(Numb);
	}
	
	long long Sum = 0;
	while (true)
	{
		if (M == 0)
			break;

		long long X = pq.top();
		pq.pop();
		long long Y = pq.top();
		pq.pop();
		long long CurXY = X + Y;

		pq.push(CurXY);
		pq.push(CurXY);
		--M;
	}

	while (!pq.empty())
	{
		Sum += pq.top();
		pq.pop();
	}
	
	std::cout << Sum;

	return 0;
}