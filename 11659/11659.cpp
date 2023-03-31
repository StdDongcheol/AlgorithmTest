

#include <iostream>
#include <vector>

int main(void)
{
	int N = 0;
	int M = 0;

	int Numb[100001] = { 0 };

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int Num = 0;
		std::cin >> Num;
		Numb[i] += Numb[i - 1] + Num;
	}
	
	for (int Count = 0; Count < M; ++Count)
	{
		int i = 0;
		int j = 0;

		std::cin >> i >> j;

		std::cout << Numb[j] - Numb[i - 1] << std::endl;
	}

	return 0;
}
// std::endl <<< 백준에서는 쓰지말기