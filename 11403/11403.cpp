// 11403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 999

int N;
int arr[100][100];

void Floyd()
{
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Numb;
			std::cin >> Numb;

			if (Numb == 1)
				arr[i][j] = 1;
			else
				arr[i][j] = INF;
		}
	}

	
	Floyd();
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(arr[i][j] == INF)
				std::cout << 0 << ' ';
			else
				std::cout << 1 << ' ';
		}
		std::cout << '\n';
	}
}