
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

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <map>
#include <unordered_map>
//
//using namespace std;
//
//std::vector<std::vector<int>> vecMap;
//std::vector<int> vecDist;
//std::vector<bool> vecCheck;
//
//int solution(int n, int r, int c)
//{
//	int answer = 0;e
//	// 현재 위치한 행의 경우, 가질수 있는 r,c의 최대값은 행 - 1
//	// 대각선으로 그었을떄, 3번째 행의 경우, 3,1 ,2,2 1,3 까지 배치.
//	// 이건 중간대각선까지만 적용됨. N번째 넘어가면 역계산 필요.
//	int CurN = r + c - 1;
//	int PrevNSum = 0;
//
//
//	// 지그재그의 경우, 등차수열로 현재 N행까지의 요소갯수를 알수 있음.
//	// 만약 N행 요소의 값을 구하려한다면
//	// 최소 N - 1행 요소값 이상이라는 말이다.
//
//	if (CurN > n)
//	{
//		CurN = n + (n - 1) - CurN + 1;
//
//		PrevNSum = CurN * (CurN - 1) / 2;
//
//		int newR = abs(r - n);
//		int newC = abs(c - n);
//
//		if (CurN % 2 == 0)
//		{
//			answer = PrevNSum + newR - (n * n);
//		}
//		else
//		{
//			answer = PrevNSum + newC - (n * n);
//		}
//	}
//
//	else
//	{
//		PrevNSum = CurN * (CurN - 1) / 2;
//
//		// 위 점과 N행이 홀짝의 경우를 이용하면 현재 인덱스가 몇번쨰인지 알수있다.
//		// 현재 N이 짝수라면 r값이 N행에서의 위치값을 가지고 있기 때문에 .
//		// 증가하는 값을 기준으로 잡았기떄문에 현재 증가중인 r을 기준
//
//		if (CurN % 2 == 0)
//		{
//			answer = PrevNSum + r;
//		}
//	}
//	
//
//	return abs(answer);
//}
//
//int main()
//{
//	deque<int> dq;
//	queue<int> q;
//	vector<string> v = {"aaa", "bbb", "ccc"};
//	map<int, int> m;
//
//	multimap<int, int> mm;
//
//	std::cout << solution(5, 3, 2) << std::endl;
//	std::cout << solution(6, 5, 4) << std::endl;
//}

#include <iostream>
#include <set>


bool Buy(__int64 N, __int64 P)
{
	int money = 2100000000;
	if (money < N * P)
		return false;
	return true;
}

void foo(int* p, int* q)
{
	// 당연히당연히 p는 q의 주소를 갖는다
	p = q;
	
	// p가 가리키는 주소(q의 주소)에 해당하는 값을 3으로 교체한다.
	*p = 3;
	return;
}

class PAClass
{
public:
	int* m_int;

	PAClass()
	{
		m_int = new int;
		*m_int = 5;
	}
	~PAClass()
	{
		printf("%d", *m_int * 2);
		delete m_int;
		m_int = 0;
	}
};

struct test
{
	//12 + 8
	int A = 0; //4 
	float C = 0.f;//4
	char B = 0;// 1
	short D = 0; //2 
	char* E;
};

class Base
{
public:
	Base()
	{
		std::cout << "Create Base" << std::endl;
	}
	virtual ~Base()
	{
		std::cout << "Delete Base" << std::endl;
	}

	void FuncA()
	{
		std::cout << "FuncA - Base" << std::endl;
	}

	virtual void FuncB()
	{
		std::cout << "FuncB - Base" << std::endl;
	}
};


class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Create Derived" << std::endl;
	}
	virtual ~Derived()
	{
  		std::cout << "Delete Derived" << std::endl;
	}
	const int& i = 0;
	void FuncA(const int& i)
	{

		std::cout << "FuncA - Derived" << std::endl;
	}

	virtual void FuncB()
	{
		std::cout << "FuncB - Derived" << std::endl;
	}
};

char* MyChar(int Num)
{
	char str[128];
	scanf_s(str, sizeof(str), "Number : %d", Num);

	return str;
}

struct str 
{
	char c;
	short s;
};

class B
{
	int* ptr;
	
	virtual void func() {};

};


// 128, 4, true
// 128, 4, false
void FuncBit(int& Target, int N, bool Flag)
{
	if (N <= 0 || Target > INT32_MAX || Target < 0)
		return;

	int bit = 1;

	bit <<= (N - 1);

	if (Flag)
	{
		Target = Target | bit;
	}
	else
	{
		Target = Target & (~bit);
	}
}

class MyClass
{
public:
	double	dd1;
	char	c1;
	double	dd2;

	MyClass() { 
		std::cout << "Myclass Created!" << std::endl; 
	};
	MyClass(const MyClass& _MyClass) 
	{ 
		dd1 = _MyClass.dd1; 
		c1 = _MyClass.c1; 
		dd2 = _MyClass.dd2; 
		std::cout << "Myclass Copied!!" << std::endl; 
	};
	//MyClass& operator=(const MyClass& _MyClass)
	//{ 
	//	dd1 = _MyClass.dd1; 
	//	c1 = _MyClass.c1; 
	//	dd2 = _MyClass.dd2; 
	//	std::cout << "Myclass Copy Assignmented!!" << std::endl; 
	//
	//	return *this;
	//};
	~MyClass() { std::cout << "Myclass Deleted!" << std::endl; };
};
MyClass func1()
{
	MyClass myclass;

	myclass.dd1 = 6;
	myclass.c1 = 'a';
	myclass.dd2 = 12;

	return myclass;
}




struct MyMode
{
	int a;
};

int main()
{
	std::list<MyMode> lsit;

	std::list<MyMode>::iterator iter;

	iter = std::find(lsit.begin(), lsit.end(), 5);

	//std::vector<int> vec = { 1,3,4,5 };
	////vec.resize(10000);
	//auto iter = vec.begin();
	//auto iterEnd = vec.end();
	//
	//std::cout << *iter;
	//vec.erase(vec.begin() + 2);
	////auto newIter= vec.insert(vec.begin() + 1, 89);
	////auto reiter = vec.begin();
	////
	////if (iter == reiter)
	////{
	////	std::cout << *iter;
	////}
	//std::list<int> nnlist;
	//
	//// 32bit : 16byte
	//// 64bit : 20byte
	//test t;
	//std::cout << '\n' << sizeof(t) << std::endl;
	////unsigned int a = 150;
	////int c = 0;
	////for (unsigned int i = 0; i < a * 2; ++i)
	////{
	////	++c;
	////}
	////std::cout << c;
	////int aa = 3, bb = 1;
	////foo(&aa, &bb);
	////
	////Buy(2000000000, 1);
	//
	//
	////PAClass value1;
	////PAClass value2 = value1;
	//
	////str s1;
	////std::cout << sizeof(s1);
	//
	////B B1;
	////std::cout << sizeof(B1);
	////int ta = 208;
	////FuncBit(ta, 5, false);
	////FuncBit(ta, 5, true);
	////printf("%d", (((0xEF >> 1) << 2)));
	//
	//std::vector<int> newVec(5, 1);
	//std::vector<int> newVec1(5, 1);
	//std::unordered_map<int, char> um;
	//
	//const int ccc = 5;	
	////std::cout << &ccc;
	//
	//{
	//	double a = 0.1f;
	//	double b = 0.3f;
	//	double c = 0.1f;
	//	double d = 0.3f;
	//
	//}
	//std::set<int, double> set1;
	//
	//std::cout << sizeof(double) << std::endl;
	//std::cout << sizeof(MyClass);
	//MyClass My;
	//MyClass My2;
	////
	////My = func1();
	//My2 = My;
	//
 	//std::cout << My.c1 << std::endl;
	//CSharedPtr<MyClass> sharedMy = new MyClass();
	//sharedMy->dd1 = 999999;
	//
	//MyClass* sharedMy2 = sharedMy;
	//
	//double ddddd = sharedMy2->dd1;


	return 0;
}