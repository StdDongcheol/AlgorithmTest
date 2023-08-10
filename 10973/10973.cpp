#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vec;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Numb;
		std::cin >> Numb;
		vec.push_back(Numb);
	}


	if (std::prev_permutation(vec.begin(), vec.end()))
	{
		for (int i : vec)
		{
			std::cout << i << " ";
		}
	}
	else
		std::cout << -1;

	return 0;
}