// 9655.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int dp[1001];

int main()
{
	int N;
	std::cin >> N;
	
	if (N % 2 == 0)
		std::cout << "CY";
	else
		std::cout << "SK";

	return 0;
}
