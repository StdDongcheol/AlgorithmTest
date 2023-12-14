// 11509.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> vecBal;
	std::vector<int> vecArr;

	for (int i = 0; i < N; ++i)
	{
		int H;
		std::cin >> H;
		vecBal.push_back(H);
	}

	vecArr.push_back(vecBal[0]);

	for (int i = 1; i < N; ++i)
	{
		bool check = false;

		for (int j = 0; j < vecArr.size(); ++j)
		{
			int CurH = vecArr[j] - 1;

			if (CurH == vecBal[i])
			{
				check = true;
				vecArr[j] -= 1;
				break;
			}
		}

		if (check == false)
		{
			vecArr.push_back(vecBal[i]);
		}
	}

	std::cout << vecArr.size();
	
	return 0;
}