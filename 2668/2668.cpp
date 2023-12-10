// 2668.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vec;
std::vector<bool> vecCheck;
int N;
int Count = 0;

void DFS(int _CurIndex, int _StartIndex, std::vector<int>& _vec)
{
	if (vecCheck[_CurIndex])
	{
		if (_CurIndex == _StartIndex)
		{
			_vec.push_back(_CurIndex);
		}

		return;
	}

	vecCheck[_CurIndex] = true;
	DFS(vec[_CurIndex], _StartIndex, _vec);
}

int main()
{
	std::cin >> N;
	vec.resize(N + 1);
	vecCheck.resize(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		int Numb;
		std::cin >> Numb;
		vec[i] = Numb;
	}

	std::vector<int> vecResult;
	for (int i = 1; i <= N; ++i)
	{
		std::fill(vecCheck.begin(), vecCheck.end(), false);

		if (vecCheck[i] == false)
			DFS(i, i, vecResult);
	}

	std::sort(vecResult.begin(), vecResult.end());

	std::cout << vecResult.size() << '\n';
	for (int Numb : vecResult)
	{
		std::cout << Numb << '\n';
	}

	return 0;
}