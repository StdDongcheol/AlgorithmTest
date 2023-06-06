// 2884.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int HH, MM;

	std::cin >> HH >> MM;
	
	int LeftM = MM - 45;

	if (LeftM < 0)
	{
		HH -= 1;
		LeftM += 60;
	}
	MM = LeftM;

	if (HH < 0)
	{
		HH = 24 + HH;
	}
	std::cout << HH << " " << MM;

	return 0;
}
