
#include <iostream>

int main()
{
	int HH, MM;
	int Timer;
	std::cin >> HH >> MM;
	std::cin >> Timer;
	int LeftM = MM + Timer;

	if (LeftM >= 60)
	{
		int HInc = LeftM / 60;
		LeftM %= 60;
		HH += HInc;
	}
	MM = LeftM;

	if (HH >= 24)
	{
		HH %= 24;
	}

	std::cout << HH << " " << MM;

	return 0;
}
