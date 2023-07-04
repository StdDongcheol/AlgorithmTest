// 2671.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>


// (100~1~|01)~

int Start = 0;
int End;
std::string str;

bool Left()
{
	Start += 3;

	while (Start < End)
	{
		if (str[Start] == '1')
		{
			while (Start < End)
			{
				if (str[Start] == '0')
					return true;
				else
				{
					Start++;
					continue;
				}
			}
		}

		else
		{
			Start++;
			continue;
		}
	}

	return false;
}

void Right()
{

}

int main()
{
	std::cin >> str;

	bool IsLeft = false;
	bool IsRight = false;
	bool LeftComplete = false;
	bool RightComplete = false;
	End = str.length();

	while (Start <= End)
	{
		if (!IsLeft || str.substr(Start + 2, 3).compare("100"))
		{
			LeftComplete = Left();
		}
	}

	if (LeftComplete)
		std::cout << "TRUE";
	else
		std::cout << "FALSE";
}
