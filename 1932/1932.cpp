// 1932.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

long long arr[501][501];
long long newArr[501][501];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)
				newArr[i][j] = newArr[i - 1][j] + arr[i][j];
			else if (j == i)
				newArr[i][j] = newArr[i - 1][j - 1] + arr[i][j];
			else
				newArr[i][j] = std::max(newArr[i - 1][j - 1], newArr[i - 1][j]) + arr[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (max < newArr[N][i])
			max = newArr[N][i];
	}

	std::cout << max;
}
