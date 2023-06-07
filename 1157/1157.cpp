// 1157.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

int Big[26];

int main()
{
	std::string str;
	std::cin >> str;

	for (int i = 0; i < str.length(); ++i)
	{
		int AlphaNumb = static_cast<int>(str[i]);

		if(AlphaNumb - 97 >= 0)
			++Big[AlphaNumb - 97];
		else
			++Big[AlphaNumb - 65];
	}

	int Count = 0;
	int index = 0;
	int MostNumb = 0;
	MostNumb = *std::max_element(Big, Big + 26);

	for (int i = 0; i < 26; ++i)
	{
		if (MostNumb == Big[i])
		{
			++Count;
			index = i;
		}
	}

	if (Count >= 2)
		std::cout << "?";
	else
		std::cout << static_cast<char>(index + 65);

	return 0;
}

