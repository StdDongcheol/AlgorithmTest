
#pragma once
#pragma warning(disable: 4996) 

#include <iostream>


struct MyNode
{
	MyNode* pPrev;
	MyNode* pNext;
	char Data[50];

public:
	MyNode()
	{
		pPrev = nullptr;
		pNext = nullptr;
		memset(Data, 0, 50);
	}
};

class MyList
{
public:
	MyList()
	{
		pStart = nullptr;
		pCurNode = nullptr;
	}
	~MyList()
	{
	}

	MyNode* pStart;
	MyNode* pCurNode;

public:
	void insert(const char* _Str)
	{
		if (pStart == nullptr)
		{
			MyNode* NewNode = new MyNode;
			size_t Size = strlen(_Str);
			strcpy(NewNode->Data, _Str);

			pStart = NewNode;
			pCurNode = NewNode;
		}
		else
		{
			MyNode* NewNode = new MyNode;
			strcpy_s(NewNode->Data, _Str);

			pCurNode->pNext = NewNode;
			NewNode->pPrev = pCurNode;
			pCurNode = NewNode;
		}
	}

	MyNode* find(const char* _Str)
	{
		MyNode* TargetNode = pStart;

		while (TargetNode != nullptr && strcmp(TargetNode->Data, _Str) != 0)
		{
			TargetNode = TargetNode->pNext;
		}
		
		return TargetNode;
	}

	void adjust(const char* _Src, const char* _Str)
	{
		MyNode* TargetNode = find(_Src);
		if (TargetNode != nullptr)
		{
			strcpy_s(TargetNode->Data, _Str);
		}
	}

	void erase(const char* _Str)
	{
		MyNode* TargetNode = find(_Str);

		if (TargetNode != nullptr)
		{
			// 첫 노드였을 경우
			if (TargetNode->pNext == nullptr && TargetNode->pPrev == nullptr)
			{
				pStart = nullptr;
				pCurNode = nullptr;

				TargetNode->pPrev = nullptr;
				TargetNode->pNext = nullptr;
				delete TargetNode;
			}

			// 맨앞 노드였을 경우
			else if (TargetNode == pStart)
			{
				MyNode* NextNode = TargetNode->pNext;

				NextNode->pPrev = nullptr;
				pStart = NextNode;

				TargetNode->pPrev = nullptr;
				TargetNode->pNext = nullptr;
				delete TargetNode;
			}

			// 마지막 노드였을 경우
			else if (TargetNode == pCurNode)
			{
				MyNode* PrevNode = TargetNode->pPrev;

				PrevNode->pNext = nullptr;
				pCurNode = PrevNode;

				TargetNode->pPrev = nullptr;
				TargetNode->pNext = nullptr;
				delete TargetNode;
			}

			// 앞뒤로 다 있다면
			else if (TargetNode->pPrev != nullptr && TargetNode->pNext != nullptr)
			{
				MyNode* PrevNode = TargetNode->pPrev;
				MyNode* NextNode = TargetNode->pNext;

				PrevNode->pNext = NextNode;
				NextNode->pPrev = PrevNode;

				TargetNode->pPrev = nullptr;
				TargetNode->pNext = nullptr;
				delete TargetNode;
			}
			
			else
			{
				_ASSERT(0);
				return;
			}
		}
	}
	void eraseAll()
	{
		MyNode* TargetNode = pStart;

		while (TargetNode != nullptr)
		{
			MyNode* NextNode = TargetNode->pNext;

			delete TargetNode;

			TargetNode = NextNode;
		}

		pStart = nullptr;
		pCurNode = nullptr;

		return;
	}

	void printAll()
	{
		MyNode* TargetNode = pStart;

		while (TargetNode != nullptr)
		{
			printf("%s\n", TargetNode->Data);
			TargetNode = TargetNode->pNext;
		}

		return;
	}
};