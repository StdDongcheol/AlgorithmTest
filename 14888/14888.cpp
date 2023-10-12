// 14888.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> numbArr;
int operatorArr[4];
int N;

int MaxVal = -2000000000;
int MinVal = 2000000000;

void Recur(int _result, int _idx)
{
	if (_idx == N)
	{
		MinVal = std::min(_result, MinVal);
		MaxVal = std::max(_result, MaxVal);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (operatorArr[i] > 0)
		{
			--operatorArr[i];
			switch (i)
			{
			case 0:
				Recur(_result + numbArr[_idx], _idx + 1);
				break;
			case 1:
				Recur(_result - numbArr[_idx], _idx + 1);
				break;
			case 2:
				Recur(_result * numbArr[_idx], _idx + 1);
				break;
			case 3:
				Recur(_result / numbArr[_idx], _idx + 1);
				break;
			}
			++operatorArr[i];
		}
	}

	return;
}

int main()
{
	std::cin >> N;
	numbArr.resize(N);

	for (int i = 0; i < N; ++i)
		std::cin >> numbArr[i];
	
	for (int i = 0; i < 4; ++i)
		std::cin >> operatorArr[i];

	Recur(numbArr[0], 1);

	std::cout << MaxVal << std::endl;
	std::cout << MinVal << std::endl;
	return 0;
}