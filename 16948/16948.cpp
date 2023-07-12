// 16948.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int arr[200][200];
bool Check[200][200];
int N;

//  (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)

int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

int EndR, EndC;

int BFS(int _r, int _c)
{
	std::queue<std::pair<int, int>> q;

	Check[_r][_c] = true;
	q.push({ _r, _c });
	arr[_r][_c] = 1;

	while (!q.empty())
	{
		int CurR = q.front().first;
		int CurC = q.front().second;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int NextR = CurR + dx[i];
			int NextC = CurC + dy[i];

			if (NextR < N && NextR >= 0 && NextC < N && NextC >= 0 && Check[NextR][NextC] == false)
			{
				Check[NextR][NextC] = true;
				arr[NextR][NextC] += arr[CurR][CurC];
				q.push({NextR, NextC});

				if (NextR == EndR && NextC == EndC)
					return arr[NextR][NextC] - 1;
			}
		}
	}

	return -1;
}

int main()
{
	int StartR, StartC;
	std::cin >> N;
	std::cin >> StartR >> StartC >> EndR >> EndC;
	std::fill(arr[0], arr[0] + 40000, 1);
	std::cout << BFS(StartR, StartC);
}
