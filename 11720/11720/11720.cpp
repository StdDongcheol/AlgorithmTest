

#include <iostream>
#include <string>


int main(void)
{
	int Answer = 0;
	int InputNumberCount = 0;
	char InputNumber[100] = { 0 };

	//std::cin >> InputNumberCount;
	//
	//for (int i = 0; i < InputNumberCount; ++i)
	//	std::cin >> InputNumber[i];
	
	long TotalNum = 70005000;
	std::string Numstr = std::to_string(TotalNum);

	std::cout << " Wait for " + Numstr << std::endl;
	
	return 0;
}