// 2437.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>

int N;

int main() 
{
	std::cin >> N;
	std::vector<int> vec(N);
	for (int i = 0; i < N; i++)
		std::cin >> vec[i];

	std::sort(vec.begin(), vec.end());

	int Sum = 0;
	for (int i = 0; i < N; i++) 
	{
		if (vec[i] > Sum + 1)
		{
			break;
		}
		Sum += vec[i];

	}

	std::cout << Sum + 1;

	return 0;
}