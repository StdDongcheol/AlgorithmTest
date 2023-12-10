// _DONOTUPLOAD.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>


std::vector<int> solution(std::vector<std::string> Maze, std::vector<std::string> Queries)
{

}

int main()
{
	std::vector<int> result;
	result = solution({ "AAAAA", "AABBB", "CAEFG", "AAEFF" },
		{ "1 1 1 5 AF", "1 1 14 5 AF", "2 1 4 5 FAE" , "1 5 4 5 ABF", "1 1 4 1 A" });

	for (int n : result)
		std::cout << n << " ";

	return 0;
}