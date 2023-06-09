// 10828.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>

int Arr[10000];
int index = -1;
int main()
{
	int N;
	std::cin >> N;


	for (int i = 0; i < N; ++i)
	{
		int Numb;
		std::string strOrder;
		std::cin >> strOrder;

		if (strOrder == "push")
		{
			std::cin >> Numb;
			++index;
			Arr[index] = Numb;
		}
		else if (strOrder == "pop")
		{
			if (index == -1)
				std::cout << -1 << '\n';
			else
			{
				std::cout << Arr[index] << '\n';
				--index;
			}
		}
		else if (strOrder == "size")
			std::cout << index + 1 << '\n';
		else if (strOrder == "empty")
			std::cout << static_cast<int>(index == -1 ? 1 : 0) << '\n';
		else if (strOrder == "top")
		{
			if (index != -1)
				std::cout << Arr[index] << '\n';
			else
				std::cout << index << "\n";
		}

	}
	return 0;
}