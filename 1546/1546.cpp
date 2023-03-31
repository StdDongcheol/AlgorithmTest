

#include <iostream>

int main(void)
{
	float Answer = 0;
	int InputNumberCount = 0;
	int ResultTest[1000] = { 0 };

	std::cin >> InputNumberCount;
	
	for (int i = 0; i < InputNumberCount; ++i)
	{
		std::cin >> ResultTest[i];
	}

	float NewTestResult = 0;

	int M = 0;

	for (int i = 0; i < InputNumberCount; ++i)
	{
		if (M < ResultTest[i])
			M = ResultTest[i];
	}

	for (int i = 0; i < InputNumberCount; ++i)
	{
		NewTestResult += ((float)ResultTest[i] / (float)M * 100.0f);
	}

	Answer = NewTestResult / InputNumberCount;

	std::cout << Answer << std::endl;

	return 0;
}