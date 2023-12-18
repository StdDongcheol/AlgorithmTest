// 28464.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::deque<int> dq;
	for (int i = 0; i < N; ++i)
	{
		int Numb;
		std::cin >> Numb;
		dq.push_back(Numb);
	}
	
	std::sort(dq.begin(), dq.end());
	
	int Park = 0, Seong = 0;
	while (dq.size() >= 2)
	{
		Seong += dq.front();
		dq.pop_front();

		Park += dq.back();
		dq.pop_back();
	}

	if (!dq.empty())
		Park += dq.back();

	std::cout << Seong << " " << Park;

	return 0;
}
