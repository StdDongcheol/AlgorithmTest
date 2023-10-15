// 14469.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec(N);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> vec[i].first >> vec[i].second;
	}
	
	std::sort(vec.begin(), vec.end());

	int CurTime = 0;
	for (int i = 0; i < N; ++i)
	{
		int EnterTime = vec[i].first;
		if (CurTime < EnterTime)
		{
			CurTime = EnterTime + vec[i].second;
		}
		else
		{
			CurTime += vec[i].second;
		}
	}

	std::cout << CurTime;

	return 0;
}