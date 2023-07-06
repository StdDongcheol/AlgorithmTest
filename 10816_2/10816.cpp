
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
	std::ios_base::sync_with_stdio(NULL);
	std::cin.tie(0);
	std::cout.tie(0);

	int sArr[500000] = {};
	int mArr[500000] = {};

	std::unordered_map<int, int> map;
	int N, M;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Numb;
		std::cin >> Numb;
		sArr[i] = Numb;

		auto iter = map.find(Numb);

		if (iter == map.end())
			map.insert(std::make_pair(Numb, 1));
		else
			++iter->second;
	}

	std::sort(sArr, sArr + N);

	std::cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int Numb;
		std::cin >> Numb;

		int Start = 0;
		int End = N - 1;
		bool Check = false;
		while (Start <= End)
		{
			int Middle = (Start + End) / 2;

			if (Numb == sArr[Middle])
			{
				std::cout << map.find(Numb)->second << ' ';
				Check = true;
				break;
			}
			else if (Numb < sArr[Middle])
				End = Middle - 1;
			else if (Numb > sArr[Middle])
				Start = Middle + 1;
		}
		if (!Check)
			std::cout << '0' << ' ';
	}
		
}