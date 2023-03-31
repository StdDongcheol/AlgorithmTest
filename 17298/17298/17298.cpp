// 17298.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>


int main()
{
	int N;
	std::vector<int> vecNum;
	std::stack<int> stkNGE;
	std::vector<int> vecNGE;

	std::cin >> N;

	vecNum.resize(N + 1);
	vecNGE.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> vecNum[i];
	}

	vecNGE[N] = -1;
	stkNGE.push(vecNum[N]);

	for (int i = N - 1; i > 0; --i)
	{
		while (!stkNGE.empty() && stkNGE.top() <= vecNum[i])
			stkNGE.pop();

		if (stkNGE.empty())
			vecNGE[i] = -1;
		else
			vecNGE[i] = stkNGE.top();

		stkNGE.push(vecNum[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		std::cout << vecNGE[i] << " ";
	}

	return 0;
}


//int main()
//{
//	int N;
//	std::vector<int> vecNum;
//	std::stack<int> stkNGE;
//	std::vector<int> vecNGE;
//
//	std::cin >> N;
//
//	vecNum.resize(N + 1);
//	vecNGE.resize(N + 1);
//
//	for (int i = 1; i <= N; ++i)
//	{
//		std::cin >> vecNum[i];
//		stkNGE.push(vecNum[i]);
//	}
//
//	int PeekNum = 0;
//	int TopNum = 0;
//
//	vecNGE[N] = -1;
//
//	PeekNum = stkNGE.top();
//	TopNum = PeekNum;
//	stkNGE.pop();
//
//	for (int i = N - 1; i > 0; --i)
//	{
//		int PopNumb = stkNGE.top();
//		stkNGE.pop();
//
//		if (PopNumb < PeekNum)
//		{
//			vecNGE[i] = PeekNum;
//			TopNum = PeekNum;
//		}
//
//		else
//		{
//			if (PopNumb < TopNum)
//				vecNGE[i] = TopNum;
//
//			else
//			{
//				TopNum = vecNum[i];
//				vecNGE[i] = -1;
//			}
//		}
//
//		PeekNum = PopNumb;
//	}
//
//	for (int i = 1; i <= N; ++i)
//		std::cout << vecNGE[i] << " ";
//
//	return 0;
//}