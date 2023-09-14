// 1991.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void Postorder(std::vector<std::vector<int>>& _vec, int _CurNode)
{
	if (_vec[_CurNode][0] == -1 && _vec[_CurNode][1] == -1)
	{
		std::cout << (char)(_CurNode + 'A');
		return;
	}
	
	if (_vec[_CurNode][0] != -1)
		Postorder(_vec, _vec[_CurNode][0]);

	if (_vec[_CurNode][1] != -1)
		Postorder(_vec, _vec[_CurNode][1]);

	std::cout << (char)(_CurNode + 'A');

	return;
}

void Preorder(std::vector<std::vector<int>>& _vec, int _CurNode)
{
	if (_vec[_CurNode][0] == -1 && _vec[_CurNode][1] == -1)
	{
		std::cout << (char)(_CurNode + 'A');
		return;
	}

	std::cout << (char)(_CurNode + 'A');

	if (_vec[_CurNode][0] != -1)
		Preorder(_vec, _vec[_CurNode][0]);
	
	if (_vec[_CurNode][1] != -1)
		Preorder(_vec, _vec[_CurNode][1]);

	return;
}

void Inorder(std::vector<std::vector<int>>& _vec, int _CurNode)
{
	if (_vec[_CurNode][0] == -1 && _vec[_CurNode][1] == -1)
	{
		std::cout << (char)(_CurNode + 'A');
		return;
	}

	if (_vec[_CurNode][0] != -1)
		Inorder(_vec, _vec[_CurNode][0]);

	std::cout << (char)(_CurNode + 'A');

	if (_vec[_CurNode][1] != -1)
		Inorder(_vec, _vec[_CurNode][1]);

	return;
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> vec(N + 1);

	for (int i = 0; i < N; ++i)
	{
		char Root, Left, Right;
		std::cin >> Root >> Left >> Right;

		int RootNumb = Root - 'A';
		int LeftNumb = Left - 'A'>= 0 ? Left - 'A' : -1;
		int RightNumb = Right - 'A'>= 0 ? Right - 'A' : -1;

		vec[RootNumb].push_back(LeftNumb);
		vec[RootNumb].push_back(RightNumb);
	}

	Preorder(vec, 0);
	std::cout << '\n';
	Inorder(vec, 0);
	std::cout << '\n';
	Postorder(vec, 0);

	return 0;
}
