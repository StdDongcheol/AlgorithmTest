// 2417.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

int main()
{
	long long N;
	std::cin >> N;
	long long q = sqrt(N);

	if (q * q < N)
	{
		++q;
	}

	std::cout << q;

	return 0;
}	