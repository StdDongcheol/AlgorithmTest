// 1966.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int main()
{
	int T;
	std::cin >> T;
	int NCount = 0;
	std::vector<int> vec;

	while (NCount < T)
	{
		std::priority_queue<int> pq;
		std::queue<std::pair<int, int>> q;
		int N, M, PrintCount = 1;
		std::cin >> N >> M;

		for (int i = 0; i < N; ++i)
		{
			int Numb;
			std::cin >> Numb;
			q.push({ Numb, i });
			pq.push({ Numb});
		}

		while (!q.empty())
		{
			int Top = pq.top();
			if (q.front().first == Top)
			{
				if (q.front().second == M)
				{
					vec.push_back(PrintCount);
					break;
				}
				pq.pop();
				q.pop();
				++PrintCount;
			}
			else
			{
				q.push(q.front());
				q.pop();
			}

		}

		++NCount;
	}

	for(int i : vec)
		std::cout << i << '\n';

	return 0;
}
