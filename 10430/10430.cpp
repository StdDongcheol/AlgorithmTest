// 10430.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int A, B, C;

	std::cin >> A >> B >> C;

	std::cout << (A + B) % C << "\n";
	std::cout << ((A % C) + (B % C)) % C << "\n";

	std::cout << (A * B) % C << "\n";
	std::cout << ((A % C) * (B % C)) % C << "\n";

	return 0;
}
