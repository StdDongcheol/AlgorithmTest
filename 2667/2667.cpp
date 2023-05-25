// 2667.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arrMap[26][26];
int Check[26][26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

int BFS(int _x, int _y, int _index)
{
	int Count = 1;
	Check[_x][_y] = true;
	arrMap[_x][_y] = _index;

	std::queue<std::pair<int, int>> q;

	q.push({ _x, _y });

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextX = CurX + dx[i];
			int NextY = CurY + dy[i];

			if (NextX > 0 && NextX <= N && NextY > 0 && NextY <= N)
			{
				if (arrMap[NextX][NextY] == 1 && !Check[NextX][NextY])
				{
					q.push({ NextX, NextY });
					Check[NextX][NextY] = true;
					arrMap[NextX][NextY] = _index;
					++Count;
				}
			}
		}
	}

	return Count;
}

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		std::string str;
		
		std::cin >> str;

		for (int j = 1; j <= str.length(); ++j)
		{
			if (str[j - 1] == '0')
				arrMap[i][j] = 0;
			else
				arrMap[i][j] = 1;
		}
	}

	int Index = 0;
	int Count = 0;
	std::vector<int> vecCount;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arrMap[i][j] == 1 && !Check[i][j])
			{
				Count = BFS(i, j, ++Index);
				vecCount.push_back(Count);
			}
		}
	}

	std::cout << Index << "\n";

	std::sort(vecCount.begin(), vecCount.end());

	for (int num : vecCount)
		std::cout << num << "\n";

	return 0;
}