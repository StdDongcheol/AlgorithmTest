#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main()
{
	int N;
	std::vector<int> vecNum;
	std::stack<int> stkNGE;
	std::vector<int> vecNGE;

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

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
		// 3 5 2 7
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
