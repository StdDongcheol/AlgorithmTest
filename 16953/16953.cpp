// 16953.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int main()
{
	long long A, B;
	long long Count = 1;
	bool check = false;
	std::cin >> A >> B;

	std::queue<std::pair<long long, long long >> q;
	q.push({ A, 1 });

	while (!q.empty())
	{
		long long CurN = q.front().first;
		long long  CurCount = q.front().second;
		q.pop();

		if (CurN == B)
		{
			check = true;
			Count = CurCount;
			break;
		}

		if (CurN * 2 <= B)
		{
			q.push({ CurN * 2 , CurCount + 1});
		}

		if (CurN * 10 + 1 <= B)
		{
			q.push({CurN * 10 + 1, CurCount + 1});
		}
	}

	if (!check)
		std::cout << -1;
	else
		std::cout << Count;
	
 	return 0;
}
