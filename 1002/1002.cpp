
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int T;
	int X1, Y1, R1, X2, Y2, R2;
	double Dist = 0;
	std::vector<int> vecCount;

	std::cin >> T;

	for (int i = 0; i < T; ++i)
	{
		std::cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

		Dist = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));

		// 무한
		if (Dist == 0 && R1 == R2)
			vecCount.push_back(-1);

		// 1개인 경우
		else if (abs(R1 + R2) == Dist || abs(R1 - R2) == Dist)
			vecCount.push_back(1);

		// 2개인 경우
		else if (abs(R1 + R2) > Dist && abs(R1 - R2) < Dist)
			vecCount.push_back(2);

		// 0개인 경우
		else
			vecCount.push_back(0);
	}

	for (int i = 0; i < T; ++i)
	{
		std::cout << vecCount[i] << "\n";
	}

	return 0;
}