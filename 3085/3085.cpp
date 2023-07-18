// 3085.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

char arr[50][50];
bool Check[50][50];
int N;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int _x, int _y)
{
	int CurMax = 1;
	for (int i = _y; i < N; ++i)
	{
		int CurCount = 1;
		
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] == arr[i][j - 1])
				++CurCount;
			else
				CurCount = 1;
			if (CurMax < CurCount)
				CurMax = CurCount;
		}
	}


	for (int i = _x; i < N; ++i)
	{
		int CurCount = 1;

		for (int j = 1; j < N; j++)
		{
			if (arr[j][i] == arr[j - 1][i])
				++CurCount;
			else
				CurCount = 1;
			if (CurMax < CurCount)
				CurMax = CurCount;
		}
	}

	return CurMax;
}

int main()
{
	std::cin >> N;
	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;

		for(int j = 0; j < str.size(); ++j)
			arr[i][j] = str[j];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				int NextX = j + dx[k];
				int NextY = i + dy[k];

				if (NextX >= 0 && NextX < N && NextY >= 0 && NextY < N)
				{
					char Temp = arr[NextY][NextX];
					arr[NextY][NextX] = arr[i][j];
					arr[i][j] = Temp;
		
					int TempAns = BFS(j, i);

					if (answer < TempAns)
						answer = TempAns;

					Temp = arr[NextY][NextX];
					arr[NextY][NextX] = arr[i][j];
					arr[i][j] = Temp;
				}
			}
		}
	}

	std::cout << answer;

	return 0;
}
