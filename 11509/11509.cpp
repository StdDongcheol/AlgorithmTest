// 11509.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <vector>

int main()
{
	std::multimap<int, int> mmBal;
	int N;
	std::cin >> N;
	std::vector<std::pair<bool, int>> vecBal;

	for (int i = 0; i < N; ++i)
	{
		int H, Dist = i;
		std::cin >> H;
		vecBal.push_back({false, H});
		mmBal.insert({ H, Dist });
	}

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (vecBal[i].first == false)
		{
			vecBal[i].first = true;
			int CurH = vecBal[i].second;

			int CurDist = i;
			while(!mmBal.empty())
			{
				auto iter = mmBal.find(CurH);

				if (iter == mmBal.end() || iter->second < CurDist)
					break;
				else
				{
					vecBal[iter->second].first = true;
					CurDist = iter->second;
					iter = mmBal.erase(iter);
					--CurH;

					if (CurH <= 0)
						break;
				}
			}
			++Count;
		}
	}
	
	std::cout << Count;
	
	return 0;
}