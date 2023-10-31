// 15683.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int map[8][8];
int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int Result = 999999999;

enum class CCTV
{
	One = 1, // 1
	Two = 2, // 2
	Three, // 3
	Four, // 4
	Five // 5
};

enum class Dir
{
	Up,
	Right,
	Down,
	Left
};

void CheckLine(int _x, int _y, Dir _Dir)
{
	int CurDir = (int)_Dir % 4;
	int NextX = _x;
	int NextY = _y;

	while (0 <= NextX && NextX < M && 
		0 <= NextY && NextY < N)
	{
		NextX = NextX + dx[CurDir];
		NextY = NextY + dy[CurDir];

		if (0 <= NextX && NextX < M && 
			0 <= NextY && NextY < N)
		{
			if (map[NextY][NextX] == 6)
				break;
			if (map[NextY][NextX] == 0)
				map[NextY][NextX] = -1;
		}
	}

	return;
}

void GetCCTVLine(std::vector<std::pair<int, int>> _vecCCTV, int _CurIndex, int _MaxSize)
{
	if (_MaxSize == _CurIndex)
	{
		int Count = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					++Count;
			}
		}
		Result = std::min(Result, Count);
		return;
	}
	
	int TempMap[8][8];

	int CurX = _vecCCTV[_CurIndex].first;
	int CurY = _vecCCTV[_CurIndex].second;
	CCTV CurCCTV = (CCTV)map[CurY][CurX];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				TempMap[j][k] = map[j][k];
			}
		}

		switch (CurCCTV)
		{
			case CCTV::One:
				CheckLine(CurX, CurY, Dir(i));
				break;
			case CCTV::Two:
			{
				CheckLine(CurX, CurY, Dir(i));
				CheckLine(CurX, CurY, Dir(i + 2));
				break;
			}
			case CCTV::Three:
			{
				CheckLine(CurX, CurY, Dir(i));
				CheckLine(CurX, CurY, Dir(i + 1));
				break;
			}
			case CCTV::Four:
			{
				CheckLine(CurX, CurY, Dir(i));
				CheckLine(CurX, CurY, Dir(i + 1));
				CheckLine(CurX, CurY, Dir(i + 2));
				break;
			}
			case CCTV::Five:
			{
				CheckLine(CurX, CurY, Dir(i));
				CheckLine(CurX, CurY, Dir(i + 1));
				CheckLine(CurX, CurY, Dir(i + 2));
				CheckLine(CurX, CurY, Dir(i + 3));
				break;
			}
		}

		GetCCTVLine(_vecCCTV, _CurIndex + 1, _MaxSize);

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				map[j][k] = TempMap[j][k];
			}
		}
	}

	return;
}

int main()
{
	std::cin >> N >> M;
	std::vector<std::pair<int, int>> vecTV;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] <= 5 && 1 <= map[i][j])
			{
				vecTV.push_back({ j, i });
			}
		}
	}

	GetCCTVLine(vecTV, 0, vecTV.size());

	std::cout << Result;

	return 0;
}