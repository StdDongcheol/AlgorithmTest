// 5639.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>

struct Node
{
	int Value;
	Node* Left;
	Node* Right;
};

std::list<Node*> listTree;
std::vector<int> vecTree(10000001, -1);

void Search(Node* _Node, int _CurVal)
{
	int ParentNumb = _Node->Value;

	if (_CurVal < ParentNumb)
	{
		if (_Node->Left != nullptr)
		{
			Search(_Node->Left, _CurVal);
		}
		else
		{
			Node* NewNode = new Node;
			NewNode->Value = _CurVal;
			NewNode->Left = nullptr;
			NewNode->Right = nullptr;

			_Node->Left = NewNode;
			return;
		}
	}

	else if (_CurVal > ParentNumb)
	{
		if (_Node->Right != nullptr)
		{
			Search(_Node->Right, _CurVal);
		}
		else
		{
			Node* NewNode = new Node;
			NewNode->Value = _CurVal;
			NewNode->Left = nullptr;
			NewNode->Right = nullptr;

			_Node->Right = NewNode;
			return;
		}
	}

	return;
}

void PostSearch(Node* _Node)
{
	if (_Node->Left != nullptr)
	{
		PostSearch(_Node->Left);
	}

	if (_Node->Right != nullptr)
	{
		PostSearch(_Node->Right);
	}

	std::cout << _Node->Value << '\n';

	return;
}

int main()
{
	while (!std::cin.eof())
	{
		int N;
		std::cin >> N;

		if (listTree.empty())
		{
			Node* NewNode = new Node;
			NewNode->Value = N;
			NewNode->Left = nullptr;
			NewNode->Right = nullptr;
			
			listTree.push_back(NewNode);
		}
		else
		{
			Node* FirstNode = *listTree.begin();

			Search(FirstNode, N);
		}
	}

	PostSearch(*listTree.begin());

	return 0;
}
