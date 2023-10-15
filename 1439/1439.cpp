// 1439.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;

	int one = 0;
	int zero = 0;

	if (str[0] == '0')
		++zero;
	else
		++one;
	
	for (int i = 1; i < str.length(); ++i)
	{
		if (str[i - 1] == str[i])
		{
			continue;
		}
		else
		{
			if (str[i] == '0')
				++zero;
			else
				++one;
		}	
	}

	if (zero >= one)
		std::cout << one << '\n';
	else
		std::cout << zero << '\n';

	return 0;
}