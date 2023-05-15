#include <iostream>
#include <vector>
#include <algorithm>

int arrN[100000] = {};
int arrM[100000] = {};

std::vector<int> vecAnswer;

int main()
{
	int N, M;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arrN[i];

	std::cin >> M;
	for (int i = 0; i < M; ++i)
		std::cin >> arrM[i];

	std::sort(arrN, arrN + N);

	for (int i = 0; i < M; ++i)
	{
		int Start = 0;
		int End = N - 1;
		int CurNumb = arrM[i];
		
		bool Check = false;
		while (Start <= End)
		{
			int Mid = (Start + End) / 2;

			if (arrN[Mid] == CurNumb)
			{
				Check = true;
				vecAnswer.push_back(1);
				break;
			}

			if (CurNumb > arrN[Mid])
			{
				Start = Mid + 1;
			}
			else
			{
				End = Mid - 1;
			}
		}
		if (!Check)
			vecAnswer.push_back(0);
	}
	
	for (int i = 0; i < vecAnswer.size(); ++i)
		std::cout << vecAnswer[i] << "\n";

	return 0;
}