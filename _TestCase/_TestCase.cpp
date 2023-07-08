#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <algorithm>
#include <cctype>

// 바이트패딩

// 패딩기준은 항상 제일 큰 타입의 사이즈를 따라간다.
// "가상함수포인터" 도 예외없이 제일 큰타입의 사이즈로 동일하게 따라감.

// 32bit나 64bit나 가상함수 "포인터"기 때문에, 사이즈 역시 동일하게 따라감.

// 그러나 타입 기준이 최우선사항임.
// 1번 우선순위 제일큰타입(ex: doubleType)
// 2번 우선순위 운영체제 bit

//class A
//{
//    int i;          // 4
//    int ii;         // 4
//    double d;       // 8
//    int _3c;         // 1
//    char _c;         // 1
//    char _2c;         // 1
//    //char c;         // 1
//    //char cc;         // 1
//    //char ccc;         // 1
//    //char cccc;         // 1
//    //int iii;           // 4
//    
//    virtual void pirnt();   // 8
//};
//
//class B
//{
//    int* m_iInt;
//
//    virtual void pirnt();
//};

// 10826.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <map>

using namespace std;

std::vector<std::vector<int>> vecMap;
std::vector<int> vecDist;
std::vector<bool> vecCheck;

int solution(int n, int r, int c)
{
	int answer = 0;
	// 현재 위치한 행의 경우, 가질수 있는 r,c의 최대값은 행 - 1
	// 대각선으로 그었을떄, 3번째 행의 경우, 3,1 ,2,2 1,3 까지 배치.
	// 이건 중간대각선까지만 적용됨. N번째 넘어가면 역계산 필요.
	int CurN = r + c - 1;
	int PrevNSum = 0;


	// 지그재그의 경우, 등차수열로 현재 N행까지의 요소갯수를 알수 있음.
	// 만약 N행 요소의 값을 구하려한다면
	// 최소 N - 1행 요소값 이상이라는 말이다.


	if (CurN > n)
	{
		CurN = n + (n - 1) - CurN + 1;

		PrevNSum = CurN * (CurN - 1) / 2;

		int newR = abs(r - n);
		int newC = abs(c - n);

		if (CurN % 2 == 0)
		{
			answer = PrevNSum + newR - (n * n);
		}
		else
		{
			answer = PrevNSum + newC - (n * n);
		}
	}

	else
	{
		PrevNSum = CurN * (CurN - 1) / 2;

		// 위 점과 N행이 홀짝의 경우를 이용하면 현재 인덱스가 몇번쨰인지 알수있다.
		// 현재 N이 짝수라면 r값이 N행에서의 위치값을 가지고 있기 때문에 .
		// 증가하는 값을 기준으로 잡았기떄문에 현재 증가중인 r을 기준

		if (CurN % 2 == 0)
		{
			answer = PrevNSum + r;
		}
	}
	

	return abs(answer);
}

int main()
{
	deque<int> dq;
	queue<int> q;
	vector<string> v = {"aaa", "bbb", "ccc"};
	map<int, int> m;

	multimap<int, int> mm;

	solution(5, 3, 2);
	solution(6, 5, 4);
}
