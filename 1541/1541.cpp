// 1541.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;

	int Sum = 0;
	bool IsMinus = false;

	std::string strNumb;
	for (int i = 0; i <= str.length(); ++i)
	{
		if (str[i] == '+' || str[i] == '-' || i == str.length())
		{
			if (IsMinus)
				Sum -= std::stoi(strNumb.c_str());
			else
				Sum += std::stoi(strNumb.c_str());

			strNumb.clear();

			if (str[i] == '-')
				IsMinus = true;
		}
		else
		{
			strNumb += str[i];
		}
	}

	std::cout << Sum;

	return 0;
}
