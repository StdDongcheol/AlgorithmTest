// 3190.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

int map[102][102];
int N, K, L;
std::queue<std::pair<int, char>> RotationQ;

enum class Dir
{
	E = 1,
	S = 2,
	W = 3,
	N = 4,
};

Dir Rotate(Dir _CurDir, char _To)
{
	Dir Result;
	if (_To == 'L')
	{
		if ((int)_CurDir - 1 <= 0)
		{
			Result = Dir::N;
		}
		else
			Result = Dir((int)_CurDir - 1);
	}
	else if (_To == 'D')
	{
		if ((int)_CurDir + 1 >= 5)
		{
			Result = Dir::E;
		}
		else
			Result = Dir((int)_CurDir + 1);
	}

	return Result;
}

void Apple(int _TailX, int _TailY, int _HeadX, int _HeadY, Dir _CurDir)
{
	if (map[_HeadX][_HeadY] == 5)
	{
		switch (_CurDir)
		{
		case Dir::E:
			map[_TailX]
			break;
		case Dir::S:
			break;
		case Dir::W:
			break;
		case Dir::N:
			break;
		}
	}
}

int Move(int _x, int _y)
{
	int Second = 0;
	int TailCount = 0;
	Dir CurDir = Dir::E;
	int CurX = _x, CurY = _y;
	int TailX = _x, TailY = _y;

	map[CurY][CurX] = (int)CurDir;

	while ()
	{
		CheckEnd();
		Moving();
		Apple();
		map[CurY][CurX] = Rotate();		// 현위치배열의 Dir 정보를 바꾼다?
	}

	return Second;
}

int main()
{
	std::cin >> N >> K >> L;
	tolower()
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		map[x][y] = 5;
	}
	
	for (int i = 0; i < L; ++i)
	{
		int sec;
		char rot;
		std::cin >> sec >> rot;
		RotationQ.push({ sec, rot });
	}

	Move(1, 1);

}
