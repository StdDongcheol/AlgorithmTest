// 10162.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int N;
int arrT[3] = { 300, 60, 10 };
int arrCount[3];

int main()
{
	int CurCount = 0;
	std::cin >> N;

	for (int i = 0; i < 4; ++i)
	{
		if (i == 3)
		{
			std::cout << -1;
			return 0;
		}
		if (N % arrT[i] == 0)
			break;
	}

	arrCount[0] = N / arrT[0];
	N -= (arrT[0] * arrCount[0]);

	arrCount[1] = N / arrT[1];
	N -= (arrT[1] * arrCount[1]);
	
	arrCount[2] = N / arrT[2];
	N -= (arrT[2] * arrCount[2]);

	for (int i = 0; i < 3; ++i)
		std::cout << arrCount[i] << " ";

	return 0;
}
