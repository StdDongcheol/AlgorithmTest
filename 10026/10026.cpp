// 10026.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

char arrMap[101][101];
bool arrCheck[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int RCount;
int GCount;
int BCount;
int RGCount;

void BFS(int _x, int _y, char _Color, bool _ColorSet)
{
	std::queue<std::pair<int, int>> q;

	q.push(std::make_pair(_x, _y));

	while (!q.empty())
	{
		int CurX = q.front().first;
		int CurY = q.front().second;
		q.pop();

		if (arrCheck[CurY][CurX])
			continue;
		
		arrCheck[CurY][CurX] = true;


		for (int i = 0; i < 4; ++i)
		{
			int NextX = dx[i] + CurX;
			int NextY = dy[i] + CurY;

			if (NextX >= 1 && NextX <= N && NextY >= 1 && NextY <= N && !arrCheck[NextY][NextX])
			{
				if (!_ColorSet && arrMap[NextY][NextX] == _Color)
					q.push(std::make_pair(NextX, NextY));

				else if(_ColorSet)
				{
					if ((_Color == 'R' || _Color == 'G') && (arrMap[NextY][NextX] == 'R' || arrMap[NextY][NextX] == 'G'))
						q.push(std::make_pair(NextX, NextY));

					else if(arrMap[NextY][NextX] == _Color)
						q.push(std::make_pair(NextX, NextY));
				}
			}
		}
	}


	if (_ColorSet && (_Color == 'R' || _Color == 'G'))
		++RGCount;

	else if(!_ColorSet)
	{
		switch (_Color)
		{
		case 'R':
			++RCount;
			break;
		case 'G':
			++GCount;
			break;
		case 'B':
			++BCount;
			break;
		}
	}
}

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			char c;
			std::cin >> c;
			arrMap[i][j] = c;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (!arrCheck[i][j])
			{
				BFS(j, i, arrMap[i][j], false);
			}
		}
	}

	std::fill(&arrCheck[0][0], &arrCheck[0][0] + 10201, false);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (!arrCheck[i][j])
			{
				BFS(j, i, arrMap[i][j], true);
			}
		}
	}

	std::cout << RCount + GCount + BCount << " " << RGCount + BCount;

	return 0;
}
