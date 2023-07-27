// 6064.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Find(int _N, int _M, int _x, int _y)
{
	int Count = 1;

	int CurX = 1;
	int CurY = 1;
	bool Check = false;
	while (_N == CurX && _M == CurY)
	{
		if (_x == CurX && _y == CurY)
		{
			Check = true;
			break;
		}

		++CurX;
		++CurY;

		if (CurX == _N)
		{
			CurX = 1;
		}
		else if (CurY == _M)
		{
			CurY = 1;
		}
		++Count;
	}

	if (!Check)
		Count = -1;
	return Count;
}

int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N, M, x, y;
		std::cin >> N >> M >> x >> y;
		std::cout << Find(N, M, x, y) << '\n';
	}

	return 0;
}
