// 1339.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

int N;
std::vector<std::string> vecStr;
int ArrNumb[26] = {};

int PriorityNumb[26] = {};
std::vector<std::pair<int, char>> vecNumb;

int Translate(std::string& _str)
{
	int ResultNumber = 0;
	int length = _str.length() - 1;
	for (int i = 0; i < _str.length(); ++i)
	{
		int Idx = _str[i] - 'A';

		ResultNumber += ((pow(10, length)) * ArrNumb[Idx]);
		--length;
	}

	return ResultNumber;
}

int main()
{
	std::cin >> N;
	vecNumb.resize(26);
	for (int i = 0; i < 26; ++i)
		vecNumb[i].second = (char)('A' + i);

	vecStr.resize(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> vecStr[i];
	}

	std::sort(vecStr.rbegin(), vecStr.rend());

	std::string LongStr = vecStr[0];

	for (int i = 0; i < vecStr.size(); ++i)
	{
		std::string str = vecStr[i];
		int length = str.length() - 1;
		for (int j = 0; j < str.length(); ++j)
		{
			// ABC -> 100A + 10B + 1C <<< 이것이 핵심
			// 자리값을 계수처럼 다루면 가장 가중치가 높은 녀석을 알 수 있다
			// vecNumb[str[j] - 'A'].first = std::max(length, vecNumb[str[j] - 'A'].first);
			vecNumb[str[j] - 'A'].first += (int)pow(10, length);
			--length;
		}
	}

	std::sort(vecNumb.rbegin(), vecNumb.rend());
	
	for (int i = 0; i < 10; ++i)
	{
		ArrNumb[vecNumb[i].second - 'A'] = (9 - i);
	}

	int sum = 0;
	for (std::string str : vecStr)
	{
		sum += Translate(str);
	}

	std::cout << sum;

	return 0;
}