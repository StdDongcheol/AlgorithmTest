// 1992.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int arr[65][65];
int N;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

void QuadTree(int _Count, int _PosX, int _PosY, std::string& _str)
{
	int CurColor = arr[_PosY][_PosX];
	bool Check = true;
	for (int i = _PosY; i < _PosY + _Count; ++i)
	{
		for (int j = _PosX; j < _PosX + _Count; ++j)
		{
			if (CurColor != arr[i][j])
			{
				Check = false;
				break;
			}
		}
		if (!Check)
			break;
	}

	if (Check == true)
		std::cout << CurColor;

	else
	{
		std::cout << '(';
		QuadTree(_Count / 2, _PosX, _PosY, _str);
		QuadTree(_Count / 2, _PosX + _Count / 2, _PosY, _str);
		QuadTree(_Count / 2, _PosX, _PosY + _Count / 2, _str);
		QuadTree(_Count / 2, _PosX + _Count / 2, _PosY + _Count / 2, _str);
		std::cout << ')';
	}
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < N; ++j)
		{
			if (str[j] == '1')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	
	std::string str;
	QuadTree(N, 0, 0, str);

	return 0;
}