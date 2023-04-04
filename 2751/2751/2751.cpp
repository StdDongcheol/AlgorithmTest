
#include <iostream>
#include <vector>


std::vector<int> Data;
std::vector<int> TempData;


void MergeSorting(int S, int E)
{
	if (E - S < 1)
		return;

	int Middle = S + (E - S) / 2;

	MergeSorting(S, Middle);
	MergeSorting(Middle + 1, E);

	int TempIndex = S;
	int LIndex = S;
	int RIndex = Middle + 1;

	for (int i = S; i <= E; ++i)
	{
		TempData[i] = Data[i];
	}

	while (LIndex <= Middle && RIndex <= E)
	{
		if (TempData[LIndex] < TempData[RIndex])
		{
			Data[TempIndex] = TempData[LIndex];
			++LIndex;
			++TempIndex;
		}

		else if (TempData[RIndex] < TempData[LIndex])
		{
			Data[TempIndex] = TempData[RIndex];
			++RIndex;
			++TempIndex;
		}
	}

	while (LIndex <= Middle)
	{
		Data[TempIndex] = TempData[LIndex];
		++LIndex;
		++TempIndex;
	}
	
	while (RIndex <= E)
	{
		Data[TempIndex] = TempData[RIndex];
		++RIndex;
		++TempIndex;
	}
}

int main()
{
	int N;

	std::cin >> N;

	Data.resize(N + 1, 0);
	TempData.resize(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> Data[i];
	}

	MergeSorting(1, N);

	for (int i = 1; i <= N; ++i)
	{
		std::cout << Data[i];
	}

	return 0;
}
