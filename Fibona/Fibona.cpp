// Fibona.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Fibo(int N, int _l, int _r)
{
	if (N == 0)
		return 0;
	else if (N == 1)
		return _r;
	else
		Fibo(N - 1, _r, _r + _l);
}

int FiboTail(int N)
{
	return Fibo(N, 0, 1);
}

int main()
{
	FiboTail(5);
}