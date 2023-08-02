// 1475.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

int arr[10];
 
int main()
{
	int N;
	std::cin >> N;
	 
	while (N >= 0)
	{
		int Numb = N % 10;
		N /= 10;

		++arr[Numb];
		if (N == 0)
			break;
	}

	int sixNine = (int)ceil((double)(arr[6] + arr[9]) / 2.f);

	arr[6] = sixNine;
	arr[9] = sixNine;

	int Count = 0;
	for (int i = 0; i < 10; ++i)
	{
		Count = std::max(arr[i] , Count);
	}

	std::cout << Count;
}
