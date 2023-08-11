// 1236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

char arr[50][50];

int main()
{
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;

		for (int j = 0; j < str.size(); ++j)
		{
			arr[i][j] = str[j];
		}
	}

	int RowCount = 0;
	int ColCount = 0;
	for (int i = 0; i < N; ++i)
	{

		bool check = false;
		for (int j = 0; j < M; ++j)
		{
			if (arr[i][j] == 'X')
			{
				check = true;
				break;
			}
		}
		if (!check)
			++RowCount;
	}

	for (int i = 0; i < M; ++i)
	{
		bool check = false;
		for (int j = 0; j < N; ++j)
		{
			if (arr[j][i] == 'X')
			{
				check = true;
				break;
			}
		}
		if (!check)
			++ColCount;
	}

	std::cout << std::max(RowCount, ColCount);
}
