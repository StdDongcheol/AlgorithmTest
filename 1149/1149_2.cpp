
#include <iostream>
#include <algorithm>

int arr[1001][3];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int r, g, b;
		std::cin >> r >> g >> b;
		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}

	for (int i = 1; i <= N; ++i)
	{
		arr[i][0] = std::min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
		arr[i][1] = std::min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
		arr[i][2] = std::min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
	}

	std::cout << std::min({ arr[N][0], arr[N][1], arr[N][2] });
}