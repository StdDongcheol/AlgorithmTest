// 1697.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[200001];
bool check[200001];

int main()
{
	std::queue<int> q;
	int N, K, X;
	int count = 0;
	std::cin >> N >> K;
	X = N;

	q.push(X);
	arr[X] = 0;
	check[X] = true;

	while (!q.empty()) 
	{
		int CurX = q.front();
		q.pop();

		if (CurX - 1 >= 0 && !check[CurX - 1])
		{
			q.push(CurX - 1);
			check[CurX - 1] = true;
			arr[CurX - 1] = arr[CurX] + 1;
		}
		if (CurX + 1 < 200001 && !check[CurX + 1])
		{
			q.push(CurX + 1);
			check[CurX + 1] = true;
			arr[CurX + 1] = arr[CurX] + 1;
		}
		if (CurX * 2 < 200001 && !check[CurX * 2])
		{
			q.push(CurX * 2);
			check[CurX * 2] = true;
			arr[CurX * 2] = arr[CurX] + 1;
		}
	}

	std::cout << arr[K];

	return 0;
}
