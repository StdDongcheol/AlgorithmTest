// 1080.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

int N, M;
std::vector<std::vector<int>> vecA;
std::vector<std::vector<int>> vecB;

void Reverse(int _X, int _Y)
{
	if (_X < N + 2 && _Y < M + 2)
	{
		for (int i = _X; i < _X + 3; ++i)
		{
			for (int j = _Y; j < _Y + 3; ++j)
			{
				vecA[i][j] = (vecA[i][j] == 1) ? 0 : 1;
			}
		}
	}
}

int main()
{
	std::cin >> N >> M;
	vecA.resize(N);
	vecB.resize(N);

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; ++j)
		{
			vecA[i].push_back((int)(str[j] - '0'));
		}
	}

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; ++j)
		{
			vecB[i].push_back((int)(str[j] - '0'));
		}
	}

	int Count = 0;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			if (vecA[i][j] != vecB[i][j])
			{
				Reverse(i, j);
				++Count;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (vecA[i][j] != vecB[i][j])
			{
				std::cout << -1;
				return 0;
			}
		}
	}

	std::cout << Count;

	return 0;
}