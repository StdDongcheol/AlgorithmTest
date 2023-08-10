// 10819.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Numb = 0;
		std::cin >> Numb;
		vec.push_back(Numb);
	}

	std::sort(vec.begin(), vec.end());
	int MaxVal = -999999999;
	do 
	{
		int Sum = 0; 
		for (int i = 0; i < N - 1; ++i)
		{
			Sum += abs(vec[i] - vec[i + 1]);
		}
		
		if (Sum > MaxVal)
			MaxVal = Sum;

	} while (std::next_permutation(vec.begin(), vec.end()));

	std::cout << MaxVal;

	return 0;
}
