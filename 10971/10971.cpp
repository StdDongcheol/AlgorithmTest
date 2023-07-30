// 10971.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int arr[10][10];
bool check[10];

int main()
{
	int Min = 999999999;
	int N;
	std::cin >> N;
	std::vector<int> vecArr;
	
	for (int i = 0; i < N; ++i)
	{
		vecArr.push_back(i);
		for (int j = 0; j < N; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	do
	{
		bool Check = true;
		int Sum = 0;
		int Start, End;
		int FirstStart = vecArr[0];

		for (int i = 0; i < N - 1; ++i)
		{
			Start = vecArr[i];
			End = vecArr[i + 1];

			if (arr[Start][End] == 0)
				Check = false;
			else
				Sum += arr[Start][End];
		}

		if (Check && arr[End][FirstStart] != 0)
		{
			Sum += arr[End][FirstStart];

			if (Sum < Min)
				Min = Sum;
		}

	} while (std::next_permutation(vecArr.begin(), vecArr.end()));

	std::cout << Min;

	return 0;
}
