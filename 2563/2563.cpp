// 2563.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

bool Check[101][101];

int main()
{
	int N;
	std::cin >> N;
	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		int maxX, maxY;

		std::cin >> x >> y;
		maxX = x + 10;
		maxY = y + 10;

		for (int j = x; j < maxX; ++j)
		{
			for (int k = y; k < maxY; ++k)
			{
				if (!Check[j][k])
				{
					Check[j][k] = true;
					++Count;
				}
			}
		}
	}

	std::cout << Count;
}
