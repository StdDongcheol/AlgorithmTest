// 2217.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> arr;
int N;

int main()
{
	std::cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}
	
	std::sort(arr.rbegin(), arr.rend());

	int Weight = 0;
	for (int i = 0; i < N; ++i)
	{
		Weight = std::max(Weight, arr[i] * (i + 1));
	}

	std::cout << Weight;
	return 0;
}