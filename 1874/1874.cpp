// 1874.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>

int main()
{
	int N;
	std::vector<int> NumArr;
	std::vector<const char*> StackArr;

	//ios_base::sync_with_stdio(false);
	//cout.tie(NULL);
	//cin.tie(NULL);

	std::cin >> N;
	NumArr.resize(N);

	for (int i = 0; i < N; ++i)
	{
		int Numb = 0;
		std::cin >> Numb;
		NumArr[i] = Numb;
	}

	std::stack<int> MyStack;
	int Index = 0;
	int Number = 1;

	MyStack.push(Number);
	StackArr.push_back("+");

	while (Number <= N)
	{
		if (!MyStack.empty())
		{
			if (MyStack.top() == NumArr[Index])
			{
				++Index;
				MyStack.pop();
				StackArr.push_back("-");
			}

			else
			{
				++Number;
				MyStack.push(Number);
				StackArr.push_back("+");
			}
		}

		else
		{
			if (MyStack.empty() && StackArr.size() == N * 2)
				break;

			else
			{
				++Number;
				MyStack.push(Number);
				StackArr.push_back("+");
			}
		}
	}

	if (StackArr.size() != N * 2)
	{
		std::cout << "NO";
	}

	else
	{
		for (int i = 0; i < StackArr.size(); ++i)
			std::cout << StackArr[i] << "\n";
	}

	return 0;
}
