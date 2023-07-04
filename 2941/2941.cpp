// 2941.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> vecWord;
bool Check[100];

int CheckAlphabet(std::string& _str)
{
	int Count = 0;
	size_t i = 0;
	size_t Size = vecWord.size();
	size_t Index = -1;

	while (i < Size)
	{
		Index = _str.find(vecWord[i], Index + 1);

		if (Index == std::string::npos)
			++i;
		else if (!Check[Index])
		{
			++Count;
			std::fill(Check + Index, Check + Index + vecWord[i].length(), true);
		}
	}

	return Count;
}

int main()
{
	std::string str;
	std::string tempStr;

	std::cin >> str;
	vecWord = { "c=", "c-","dz=","d-", "lj", "nj", "s=", "z=" };

	int Start = 0;
	size_t Length = str.length();
	int Count = 0;

	Count += CheckAlphabet(str);

	for (size_t i = 0; i < Length; ++i)
		if (Check[i] == false)
			++Count;

	std::cout << Count;

	return 0;
}
