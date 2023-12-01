

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <list>

class MyData
{

};

void F()
{
	std::vector<std::auto_ptr<MyData>> vec;
	std::list<int> liost;
	
	return;
}

int main()
{
	F();
	std::list<int> L1;
	std::list<int> L2;
	L1.push_back(1);
	L1.push_back(3);
	L1.push_back(5);
	L1.push_back(7);
	L1.push_back(9);

	L2.push_back(2);
	L2.push_back(4);
	L2.push_back(6);
	L2.push_back(8);
	auto iter = L1.begin();
	L1.splice(iter, L2, L2.begin(), L2.end());

	L2.clear();

	
	std::vector<int> vec1 = {40};
	std::vector<int> vec2 = {1, 3, 5, 6, 8};


	int a = 0;

	return 0;
}