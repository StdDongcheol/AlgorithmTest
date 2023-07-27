// 1759.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int L, C;
bool arr[16];
std::vector<char> vecChar;

void Func(int _count, std::vector<char>& _vec, bool _motherCheck, int _sonCheck)
{
	if (_count == L)
	{
		if (!_motherCheck || _sonCheck < 2)
			return;
		for (int i = 0; i < _vec.size(); ++i)
		{
			std::cout << _vec[i];
		}
		std::cout << '\n';

		return;
	}


	for (int i = 0; i < vecChar.size(); ++i)
	{
		if (!arr[i])
		{
			arr[i] = true;
			_vec.push_back(vecChar[i]);

			switch (vecChar[i])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				{
					Func(_count + 1, _vec, true, _sonCheck);
					break;
				}
				default:
				{
					Func(_count + 1, _vec, _motherCheck, _sonCheck + 1);
					break;
				}
			}
			_vec.pop_back();
			arr[i] = false;
		}
	}
}

int main()
{
	std::cin >> L >> C;
	vecChar.resize(C);
	for (int i = 0; i < C; ++i)
		std::cin >> vecChar[i];

	std::sort(vecChar.begin(), vecChar.end());

	std::vector<char> vec;
	Func(0, vec, false, 0);
}