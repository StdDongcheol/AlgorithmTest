// 2470.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int arrN[100000];

int main()
{
	int N;
	int Value = 2000000000;
	int ValueStart = 0;
	int ValueEnd = 0;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
		std::cin >> arrN[i];

	std::sort(arrN, arrN + N);
	int Start = 0, End = N - 1;

	while (Start < End)
	{
		if (abs(arrN[Start] + arrN[End]) < abs(Value))
		{
			Value = arrN[Start] + arrN[End];
			ValueStart = Start;
			ValueEnd = End;
		}

		if (arrN[Start] + arrN[End] <= 0)
			++Start;
		else if (arrN[Start] + arrN[End] > 0)
			--End;
	}

	std::cout << arrN[ValueStart] << " " << arrN[ValueEnd];
}